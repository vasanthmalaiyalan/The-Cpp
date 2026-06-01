#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <stdexcept>

// ----------------------------------------------
// Simulates the internal buffer of std::cin
// In real cin, keyboard input goes into a buffer first
// then >> operator reads from that buffer
// ------------------------------------------------
class MyBuffer {
    private:
      std::string data; // raw input stored here (like keyboard buffer)
      int  pos; // current read position in buffer

    public:
      MyBuffer() : pos(0) {}
      
      // simulate user typing something + pressing Enter
      // In real cin, OS sends keyboard chars into this buffer
      void receiveInput(const std::string& input) {

        data = input + '\n'; // \n = Enter key
        pos = 0;  // reset read position
      }

      // read one character from buffer (like internal getc())
      // return -1 if buffer is exhauted (EOF)
      int readChar() {
        if (pos >= (int)data.size()) {
            return -1; // EOF: nothing left in buffer
        }
        return data[pos++]; // return char, advance position
      }

      // peek at current char without consuming it
      int peekChar() {
        if (pos >= (int)data.size()) {
            return -1;
        }
        return data[pos];
      }
};

// --------------------------------------------
// Simulates std::basic_ios state tracking
// Real cin uses these exact bit flags internally
// ----------------------------------------------
class MyStreamState {
    protected: // inheritance
       int state; // bit field storing stream health

    public:
      static const int eofbit = 1; // 0001: input exhausted
      static const int failbit = 2; // 0010: parse failed (wrong type)
      static const int badbit = 4; // 0100: serious internal error
      
      MyStreamState() : state(0) {}

      // good(): return true only when NO bits are set
      // cin.good() ->true means "safe to keep reading"
      bool good()  const { return state == 0; }

      // eof(): return true when eofbit is set
      // cin.eof() -> true means "no more input available"
      bool eof() const { return state & eofbit; }

      // fail(): return true when failbit is set
      // cin.fail() -> true means ">> could not parse the value"
      bool fail() const { return state & failbit; }

      // bad(): return true when badbit is set
      // cin.bad() -> true "stream is broken"
      bool bad() const { return state & badbit; }

      // clear(): resets ALL bits back to 0
      // cin.clear() -> makes cin usable again after a fail
      void clear() { state = 0; }

      // operator bool: lets you write if (!(cin >> value))
      // return false when fail or bad bit is set
      explicit operator bool() const {
        return !(state & (failbit | badbit));
      }
};

// ----------------------------------------------
// Simulates std::istream (the class cin belongs to)
// Combines buffer + state + >> operator logic
// ------------------------------------------------
class MyInputStream : public MyStreamState {
    private:
       MyBuffer buffer; // internal keyboard buffer
       bool  eofForced; // true when user force EOF ()

       // skip whitespace characters in buffer
       // real cin does this automatically before parsing
       void skipWhitespace() {
        while (true) {
            int ch = buffer.peekChar();
            if (ch == -1) break;  // buffer empty
            if (ch != ' ' && ch != '\t' && ch != '\n') break;
            buffer.readChar();  // consume whitespace
        }
       }

    public:
      MyInputStream() : eofForced(false)  {}
      
      // simulate user typing input (like keyboard entry)
      void simulateUserTyping(const std::string& input) {
        eofForced = false;
        clear(); // reset state for new input
        buffer.receiveInput(input); // load into buffer
      }

      // simulate CTRL+D / ctrl+z -> forces EOF
      void simulateEOF() {
        eofForced = true;
        state |= eofbit; // set eofbit directly
      }

      // --->> operator for int -------------------
      // This is what cin >> value calls internally
      // steps: skip whitespace -> read digits -> parse int
      MyInputStream& operator>>(int& value) {
        // Step 1: if already in bad state, do nothing
        if (bad()) {
            return *this;
        }

        // Step 2: if EOF forced, set bits and return 
        if (eofForced) {
            state |= (eofbit | failbit);
            return *this;
        }

        // Step 3: skip spaces/tabs/newlines
        skipWhitespace();

        // Step 4: check if buffer is empty after skipping
        if (buffer.peekChar() == -1) {
            state |= (eofbit | failbit); // nothing to read
            return *this;
        }

        // Step 5: read characters and try to build an integer
        std::string token;
        bool hasDigit = false;

        // allow optional leading minus sign
        if (buffer.peekChar() == '-') {
            token += (char)buffer.readChar();
        }

        // read digit characters one by one
        while (true) {
            int ch = buffer.peekChar();
            if (ch == -1) break; // buffer empty
            if (ch < '0' || ch > '9') break; // non-digit stops reading
            token += (char)buffer.readChar(); // consume digit
            hasDigit = true;
        }

        // Step 6: if no digits found -> failbit (like typing "abc")
        if (!hasDigit) {
            state |= failbit;
            return *this;  
        }

        // Step 7: convert collected digits string -> int
        // real cin uses strtol() internally for this
        value = std::stoi(token);

        // Step 8: success -> state stays good (no bits set)
        return *this;
      }

      // simulate cin.ignore(max, '\n);
      // discard characters from buffer until '\n' or end
      void ignore() {
        while (true) {
            int ch = buffer.readChar();
            if (ch == -1 || ch == '\n') break; // stop at newline or EOF
        }
      }
};

// -------------------------------------------
// Our custom cin (same design as real std::cin)
// ---------------------------------------------

MyInputStream myCin;

// ---------------------------------------------
// Mirror the real get_numbers_1_to_10() exactly
// but uses myCin instead of std::cin
// so we ccan SEE everyinternal step
// -----------------------------------------------

int get_numbers_1_to_10(const std::string& simulatedInput, bool forceEOF = false) {
    if (forceEOF) {
        myCin.simulateEOF();
    }
    else {
        myCin.simulateUserTyping(simulatedInput);
    }

    while (true) {
        std::cout << "Enter an integer (1-10): " << simulatedInput << '\n';

        int value {};

        // --- >> operator runs here ---------------
        // internally: skipWhitespace -> read chars -> parse int
        // return *this (the stream). cast to bool:
        // true = parse success
        // false = parse failed or EOF
        if (!(myCin >> value)) {

            // stream returned false -> something went wrong
            if (myCin.eof()) {

            // eofbit is set -> no more input possible
            // real cin: 
            throw std::runtime_error("Input closed by user");
        }

        if (myCin.fail()) {

            // failbit is set -> >> could not parse an int
            // real cin: user typed "abc" or "3.5"etc
            std::cout << "Not an integer. Try again.\n";

            // clear(): resets failbit so >> works again
            // without this, every future >> would instantly fail
            myCin.clear();

            // ignore(): flushs remaining bad chars fro buffer
            // real cin: discards "abc\n" so next >> starts fresh
            myCin.ignore();

            continue; // loop back, ask again

        }
    }

    // >> succeeded -> value holds the parsed integer
    // now check if it is within allowed range
    if (value < 1 || value > 10) {
        std::cout << "Number must be between 1 and 10.\n";
        continue; // loop back, ask aain
    }

    return value; // vaild integer in range -> done
 }
}

// -------------------------------------------
// main: runs all four real-world scenarios
// -------------------------------------------

int main() {

    std::cout << "=== Case 1: Vaild input (5) ===\n";
    try {
        int result = get_numbers_1_to_10("5");
        std::cout << "Accepted value: " << result << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "\n=== Case 2: Out of range (15) ===\n";
    try {

        // outt of range -> loop would ask again in real program
        // here we just show the first iteration message
        int result = get_numbers_1_to_10("155");
        std::cout << "Accepted value: " << result << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "\n=== Case 3: Wrong type (abc) ===\n";
    try {
        int result = get_numbers_1_to_10("abc");
        std::cout << "Accepted value: " << result << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    std::cout << "\n=== Case 4: EOF ===\n";
    try {
        int result = get_numbers_1_to_10("", true);
        std::cout << "Accepted value: " << result << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}

/*
 ./a.out
=== Case 1: Vaild input (5) ===
Enter an integer (1-10): 5
Accepted value: 5

=== Case 2: Out of range (15) ===
Enter an integer (1-10): 155
Number must be between 1 and 10.
Enter an integer (1-10): 155
Input closed by user

=== Case 3: Wrong type (abc) ===
Enter an integer (1-10): abc
Not an integer. Try again.
Enter an integer (1-10): abc
Input closed by user

=== Case 4: EOF ===
Enter an integer (1-10):
Input closed by user
*/