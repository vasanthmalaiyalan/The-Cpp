# 🧠 Final Roadmap — Browser Engine + Exploitation

---

![alt text](image-1.png)

Romba, this is the exact skill set that separates Google P1 bug bounty hunters from everyone else. Let me break down the full chain — every stage, the knowledge required, the 2025-2026 landscape, and an honest book map.

Here's the architecture of the full chain first, then I'll go deep on each stage.Now let's go deep on each stage — what you need to master, what actually happened in 2025-2026, and the honest book map.

---

## Stage 1 — V8 / Wasm RCE (Renderer)

This is where the chain begins. You need initial arbitrary read/write inside the V8 heap.

**What to learn:**

V8's object model is everything here. Every JS object has a `Map` (hidden class). TurboFan and Maglev (the two JIT tiers) speculate on these Maps. When they get it wrong — through redundancy elimination, escape analysis, or type feedback pollution — you get type confusion. The classic primitive is `addrOf(obj)` (leak a heap address) and `fakeObj(addr)` (treat an attacker-controlled address as a JS object). From there you corrupt an `ArrayBuffer`'s backing store pointer to get arbitrary R/W.

The 2025 landscape showed that TurboFan's CheckMaps optimization was the repeated attack surface — the optimizer incorrectly marks a CheckMaps node as redundant, allowing a side-effecting function to change an object's Map without the engine noticing.

WebAssembly is now a parallel attack surface. At TyphoonPWN 2025, researcher Seunghyun Lee (0x10n) exploited a Wasm type canonicalization bug — an improper nullability check in `CanonicalEqualityEqualValueType` — using a birthday attack on MurmurHash64A to achieve nullability confusion on reference types, which undermined Wasm type safety guarantees entirely.

**Core knowledge required:**
- V8 object internals: Maps, Shapes, Hidden Classes, SMI vs HeapObject tagging
- TurboFan/Maglev IR: Nodes, sea-of-nodes, CheckMaps, BoundsCheckElimination
- Wasm GC type system: reference types, nullability, canonicalization
- JIT spraying, ROP construction in a browser context
- ASLR bypass techniques: `%DebugPrint`, heap spray, info leak via OOB read

---

## Stage 2 — V8 Sandbox Escape

This is the new wall Google added. As of 2024-2025, getting arbitrary R/W inside the V8 heap no longer gives you Renderer process control — the sandbox "cages" the V8 heap.

**What changed:**

In 2025, getting `addrOf` and `fakeObj` primitives is no longer enough because the V8 Sandbox constrains the attacker to only corrupt memory inside the cage — they cannot overwrite return addresses on the stack or modify partition allocators outside it.

The new techniques target structures that bridge inside-sandbox to outside-sandbox:

- **ExternalPointerTable (EPT)** — compressed pointers to outside-sandbox memory go through this table. Corrupt a table entry to redirect to attacker-controlled memory outside the cage.
- **WasmInstance jump table** — by corrupting the jump table of a WebAssembly instance (which resides inside the sandbox), attackers can redirect execution to arbitrary shellcode compiled via JIT.
- **JSPI (JS Promise Integration) secondary stack** — the novel V8 sandbox bypass used at TyphoonPWN 2025 abused JavaScript Promise Integration's state-switching flaws to orchestrate a stack pivot outside the sandbox.
- **TrustedPointerTable** — newer Chromium versions moving sensitive pointers here; finding a way to corrupt entries is current research frontier.

---

## Stage 3 — Chrome Sandbox Escape (SBX2)

Now you have full Renderer process memory. The Renderer runs under a highly restricted OS sandbox (seccomp on Linux, Job Objects + AppContainer on Windows). You need to escape to the Browser process or GPU process.

**The dominant 2025-2026 vector: Mojo IPC logic bugs.**

CVE-2025-2783 highlighted the danger of logic bugs in Mojo IPC. The vulnerability came from the Browser Process failing to validate permissions of a handle passed by the Renderer — an attacker controlling the Renderer could forge a specific IPC message, tricking the privileged Browser Process into a restricted action. This type of logic bug is notoriously difficult to prevent with memory safety mitigations like MTE or CFI because the control flow is valid; only the intent is malicious.

**The 2025 ipcz vector:** CVE-2025-4609 was a flaw in Chromium's `ipcz` IPC mechanism — a compromised renderer could manipulate the `destination_type` field to `kBroker` during serialization, bypassing handle validation and acquiring privileged browser process handles. This earned a $250,000 payout.

**The ANGLE/GPU vector:**

CVE-2025-14174 was not a JS engine flaw but an ANGLE out-of-bounds access — by overwriting vtable pointers of C++ objects, attackers redirect control flow to a ROP chain achieving code execution within the GPU process. Since the GPU process holds higher privileges than the renderer (direct driver access), it serves as a highly effective pivot point.

**What to learn:**
- Chrome's multi-process architecture: Renderer, Browser, GPU, Network, Utility processes
- Mojo IDL, message pipe semantics, handle table management
- ipcz internals: node names, broker model, `Transport::Deserialize`
- How to read `.mojom` interface definitions and find TOCTOU / permission confusion
- ANGLE: WebGL → OpenGL/D3D translation layer, shader compiler attack surface

---

## Stage 4 — LPE (Kernel Privilege Escalation)

You're now executing as a normal user in the Browser process. To become SYSTEM/root, you need an OS-level vulnerability.

**Windows:** CVE-2023-21674, a Windows kernel UAF vulnerability in ALPC (Advanced Local Procedure Call), was used to escape the Chrome sandbox in a full chain — the dangling pointer in `WaitingThread` via `LpcpCopyRequestData` allowed arbitrary kernel memory manipulation to elevate privileges.

**Linux (from renderer directly):** When a renderer exploit needs a kernel pivot that stays inside the seccomp profile, abusing AF_UNIX MSG_OOB sockets reachable inside the sandbox provides a deterministic path for an SKB UAF → kernel RCE chain.

**What to learn:**
- Windows kernel: ALPC internals, win32k.sys attack surface, pool allocation
- Linux kernel: seccomp filter bypass techniques, kernel heap exploitation (SLAB/SLUB), namespace escapes
- macOS: IOKit, XPC privilege separation, SIP bypass
- Heap shaping, cross-cache attacks, CPU mitigations (SMEP/SMAP, KPTI bypass)

---

## Honest Book Map

This is what you actually need — mapped to your current CS:APP → C++ path.

| Layer | Book | Why it matters for this chain |
|---|---|---|
| **Foundation** | CS:APP (you're doing it) | Memory layout, calling conventions, buffer overflows, linking — everything the exploit primitives sit on |
| **C++ mastery** | Effective Modern C++ | V8 and Chromium are C++14/17; understanding move semantics, smart pointers, RAII is essential for reading source |
| **Exploitation fundamentals** | Hacking: Art of Exploitation | shellcode, stack/heap exploitation mechanics, the mental model for all of stage 1-2 |
| **Binary analysis** | Practical Binary Analysis | Disassembly, ELF internals, patching, reverse engineering Chromium builds |
| **Browser internals** | Web Browser Engineering | How the renderer pipeline works end to end — Blink layout, painting, JS execution |
| **V8 source** | *No book — read the source* | `src/compiler/`, `src/objects/`, `src/wasm/` in the V8 repo. Blog posts from v8.dev |
| **Kernel exploitation** | *The Linux Kernel* (Robert Love) + Linux Kernel Exploitation (phrack/papers) | Stage 4 — you need kernel internals for LPE |
| **IPC / Mojo** | *No book — read Chromium docs* | `docs/mojo_ipc_conversion.md`, `ipcz/` source, Chromium's `//mojo/` directory |
| **Code auditing** | Art of Software Security Assessment | Finding the class of bugs (logic errors, type confusion, handle mismanagement) that dominate 2025 |
| **Network layer** | Attacking Network Protocols | Less critical for this specific chain but useful for delivery vectors |

---

## The Real Skill Gap — What Books Can't Teach

The hardest parts of this chain have no book:

**Reading Chromium source cold.** The codebase is ~35 million lines. You need to learn to navigate it — `git log --grep`, `git blame`, reading Gerrit code reviews, understanding `DEPS` files and component boundaries.

**Variant analysis.** After you understand one CVE (say, a TurboFan redundancy elimination bug), you audit similar patterns in the same pipeline looking for siblings. This is how top researchers find bugs — not fuzzing, but understanding a bug class and manually reviewing all related code paths.

**Patch diffing.** Identifying the vulnerable code path involves analyzing source code changes between affected and patched Chrome versions to pinpoint the exact fix, then reverse-engineering the exploit primitive from the patch.

**Practical starting path for you right now:** After finishing CS:APP, go to the V8 blog (`v8.dev/blog`) and read every post tagged "security". Then pick one disclosed CVE (CVE-2025-13223 is well-documented), read the patch commit, read the TurboFan source around it, and try to understand why the CheckMaps node was incorrectly eliminated. That exercise is worth more than any chapter in any book.

The Pwn2Own/TyphoonPWN competitions are your target — that's where full chains are demonstrated and the writeups published. Start consuming every writeup from Theori, Exodus Intelligence, and Google Project Zero.

## 1️⃣ Computer Systems Fundamentals

**Start with how computers actually run programs.**

**Books:**
```
Computer Systems: A Programmer's Perspective
Modern x86 Assembly Language Programming
```

**Learn:**
```
memory layout
stack vs heap
CPU pipeline
assembly instructions
compiler behavior
```

✔ These are essential for memory corruption bugs

---

## 2️⃣ Core C / C++ Mastery

**Books:**
```
Programming: Principles and Practice Using C++
Effective Modern C++
C++20: The Complete Guide
A Tour of C++
```

**Topics:**
```
RAII
templates
move semantics
smart pointers
undefined behavior
```

✔ Browsers like Chromium are mostly C++

---

## 3️⃣ Algorithms + Problem Solving

**Books:**
```
Introduction to Algorithms
Programming Pearls
```

**Why Programming Pearls matters:**
```
teaches algorithmic thinking
teaches performance-oriented coding
teaches debugging strategies
```

**Example mindset from the book:**
```
Write correct code
      ↓
Measure performance
      ↓
Optimize only the bottleneck
```

✔ This mindset is used in systems engineering

---

## 4️⃣ Mathematics for Computer Science

**Books:**
```
Discrete Mathematics and Its Applications
Introduction to Probability
```

**Used for:**
```
algorithm reasoning
graph structures
fuzzing strategies
complexity analysis
```

---

## 5️⃣ Multithreading / Concurrency ⚡

**Book:**
```
C++ Concurrency in Action
```

**Topics:**
```
threads
atomics
memory ordering
lock-free programming
race conditions
false sharing
```

**Example:**
```cpp
std::atomic<int> counter{0};
counter++;
```

**Very important for browsers because:**
```
JavaScript engine threads
rendering threads
network threads
GPU process
```

**Concurrency bugs can cause:**
```
race conditions
use-after-free
```

---

## 6️⃣ Linux Systems Programming

**Books:**
```
The Linux Programming Interface
UNIX Network Programming
Systems Performance: Enterprise and the Cloud
```

**Topics:**
```
processes
threads
IPC
sockets
epoll
system calls
```

✔ Browsers interact heavily with the OS kernel

---

## 7️⃣ Performance Engineering

**Book:**
```
Optimizing Software in C++
```

**Learn:**
```
cache locality
CPU pipelines
branch prediction
memory alignment
```

**Example performance idea:**
```
Bad:  random memory access
Good: sequential memory access
```

✔ Critical for high-performance engines like V8

---

## 8️⃣ Browser Architecture

**Book:**
```
Web Browser Engineering
```

**Topics:**
```
HTML parser
CSS parser
DOM tree
layout engine
rendering pipeline
```

**Browser pipeline:**
```
HTML
 ↓
DOM
 ↓
CSS styles
 ↓
Layout
 ↓
Paint
 ↓
Screen
```

✔ This explains Blink rendering engine concepts

---

## 9️⃣ Security Research / Exploitation

**Books:**
```
The Art of Software Security Assessment
The Shellcoder's Handbook
Fuzzing for Software Security Testing and Quality Assurance
Practical Binary Analysis
Attacking Network Protocols
```

**Topics:**
```
reverse engineering
fuzzing
exploit development
memory corruption
```

**Example vulnerability:**
```
Use-after-free
      ↓
Corrupt pointer
      ↓
Control instruction pointer
      ↓
Remote code execution
```

---

## 🔟 V8 Engine Internals (Final Step)

**After everything above — Study V8 JavaScript engine.**

**Important concepts:**
```
bytecode interpreter
hidden classes
inline caching
JIT compiler
garbage collection
```

**Flow:**
```
JavaScript
    ↓
V8 bytecode
    ↓
JIT optimized machine code
```

✔ Most Chrome vulnerabilities come from V8 bugs

---

## 🎯 Final Skill Set After This Roadmap

**You will understand:**
```
Computer architecture
Assembly
C/C++
Algorithms
Concurrency
Operating systems
Networking
Browser engines
JavaScript engines
Binary exploitation
Fuzzing
```

✔ This combination is exactly what elite browser security researchers know

---

## ✅ Final Answer

> Yes — adding **C++ Concurrency in Action** and **Programming Pearls** makes your roadmap complete and well-balanced.