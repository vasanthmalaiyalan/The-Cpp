#include <iostream>
#include <limits>

// --------------------------------------------
// Base class : holds stream state (like std::basic_ios)
// --------------------------------------------

class MyStream {

    private:
       int state; // bit field: 0 = good, 1 = eofbit, 2 = failbit, 4 = badbit

    public:
       // State bit constants
       static const int eofbit = 1; // 0001
       static const int failbit = 2; // 0010
       static const int badbit = 4; // 0100
       
       // Constructor: start in good state
       MyStream() : state(0) {}

       // ----- state query functions ---------

       // eof() -> return true if eofbit is set
       // Example: cin.eof() -> true when ctrl+d pressed
       bool eof() const { return state & eofbit; }

       // fail() -> return true if failbit is set
       // Example: cin.fail() -> true when "abc" given instead of int
       bool fail() const { return state & failbit; }

       // bad() -> return true if badbit is set
       // Example: serious harware/buffer error occurred
       bool bad() const { return state & badbit; }

       // good() -> reeturn true only when state is 0 (no bits set)
       // Example : cin.good() -> true when everything is fine
       bool good() const { return state == 0; }
       // --------- State modifier functions -------------

       // clear() -> resets all bits back to 0 (good state)
       // Example: cin.clear() after a fail, so cin can read again
       void clear() { state = 0; }

       // setEof() -> simulate EOF (like pressing Ctrl+D)
       void setEof() { state |= eofbit; }

       // setFail() -> simulate Fail (like typing "abc" for an int)
       void setFail() { state |= failbit; }

       // setBad() -> simulate BAD (like a hardware read error)
       void setBad() { state |= badbit; }

       // ------ Print current state ----------------
       void printState() const {

        std::cout << " good() = " << good() << '\n';
        std::cout << " eof() = " << eof() << '\n';
        std::cout << " fail() = " << fail() << '\n';
        std::cout << " bad() = " << bad() << '\n';
       }
};

// ----------------------------------------------
// Derived class: inherits all state function
// (like std::ifstream inherits from std::basic_ios)
// -----------------------------------------------
class MyFileStream : public MyStream {
    public:
      // pretend open: if filename is empty -> set failbit
      void open(const std::string& filename) {

        if (filename.empty()) {
            setFail(); // file not found -> fail
        }
        else {
            clear(); // file opened fine -> good state
        }
      }
};

int main() {
    // ----- Test 1: Fresh stream -> good state ------
    std::cout << "=== Test 1: Fresh stream ===\n";
    MyStream s1;
    s1.printState();
    // good()=1, eof()=0, fail()=0, bad()=0

    // ----- Test 2: Simulate EOF ----------------
    std::cout << "\n=== Test 2: EOF set () ========\n";
    MyStream s2;
    s2.setEof();
    s2.printState();
    // good()=0 eof()=1, fail()=0, bad()=0

    // --------- Test 3: Simulate FAIL ------------
    std::cout << "\n=== Test 3: Fail set (wrong type input) ====\n";
    MyStream s3;
    s3.setFail();
    s3.printState();
    // good()=0, eof()=0, fail()=1, bad()=0

    // --------- Test 4: clear() resets state -------
    std::cout << "\n=== Test 4: After clear() ===\n";
    s3.clear();
    s3.printState();
    // good()=1, eof()=0, fail()=0, bad()=0

    // ---- Test 5: BAD state -------------
    std::cout << "\n=== Test 5: BAD set (hardware error) ===\n";
    MyStream s4;
    s4.setBad();
    s4.printState();
    // good()=0, eof()=0, fail()=0, bad()=1

    // -------- Test 6: Derived class (MyFileStream) -----
    std::cout << "\n=== Test 6: MyFileStream - file not found ===\n";
    MyFileStream fs;
    fs.open(""); // empty name -> fail
    fs.printState();
    // good()=0, fail()=1 <- inherited from MyStream!

    std::cout << "\n=== Test 7: MyFileStream - file open ok ===\n";
    fs.open("data.txt"); // vaild name -> good
    fs.printState();
    // good()=1, all other 0

    return 0;
}

/*
/a.out
=== Test 1: Fresh stream ===
 good() = 1
 eof() = 0
 fail() = 0
 bad() = 0

=== Test 2: EOF set () ========
 good() = 0
 eof() = 1
 fail() = 0
 bad() = 0

=== Test 3: Fail set (wrong type input) ====
 good() = 0
 eof() = 0
 fail() = 1
 bad() = 0

=== Test 4: After clear() ===
 good() = 1
 eof() = 0
 fail() = 0
 bad() = 0

=== Test 5: BAD set (hardware error) ===
 good() = 0
 eof() = 0
 fail() = 0
 bad() = 1

=== Test 6: MyFileStream - file not found ===
 good() = 0
 eof() = 0
 fail() = 1
 bad() = 0

=== Test 7: MyFileStream - file open ok ===
 good() = 1
 eof() = 0
 fail() = 0
 bad() = 0

*/

