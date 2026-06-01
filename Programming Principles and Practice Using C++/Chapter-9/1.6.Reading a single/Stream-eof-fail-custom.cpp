#include <iostream>
#include <string>

// ─────────────────────────────────────────
// Stream State Flags - bit positions
// ஒவ்வொன்றும் ஒரு bit மட்டுமே
// ─────────────────────────────────────────
namespace StreamBits {
    constexpr int goodbit = 0b0000; // 0 - எல்லாம் சரி
    constexpr int eofbit = 0b0001; // 1 - buffer முடிந்தது
    constexpr int failbit = 0b0010; // 2 - படிக்க தோல்வி
    constexpr int badbit = 0b0100; // 4 - buffer பாதிப்பு
}

// ─────────────────────────────────────────
// MyStream Class
// std::istream போன்று நாமே உருவாக்கியது
// ─────────────────────────────────────────

class MyStream {
    private:
      int m_state {StreamBits::goodbit }; // தொடக்கத்தில் good
      std::string m_bufffer {};  // raw data சேமிக்கும் இடம்

    public:
       // Constructor - string-ஐ buffer-இல் சேமிக்கிறது
       MyStream(const std::string& data) : m_buffer(data) {}

      // ─────────────────────────────────────
      // State check functions
      // m_state-இல் உள்ள bits-ஐ சோதிக்கின்றன
      // ─────────────────────────────────────

      // any bits set or not?
      bool good() const { return m_state == StreamBits::goodbit; }

      // eofbit set 
      bool eof() const { return m_state & StreamBits::eofbit; }

      // failbit or badbit set?
      bool fail() const { return m_state & (StreamBits::failbit | StreamBits::badbit); }

      // badbit set ?
      bool bad() cosnt { return m_state & StreamBits::badbit; }

    // ─────────────────────────────────────
    // operator bool
    // while (stream >> value) வேலை செய்ய தேவை
    // good() true → loop தொடரும்
    // good() false → loop நிற்கும்
    // ─────────────────────────────────────
    
    operator bool() const { return good(); }

    // ─────────────────────────────────────
    // operator>>
    // string buffer-இல் இருந்து int படிக்கிறது
    // stoi மூலம் string → int மாற்றுகிறது
    // ─────────────────────────────────────
    MyStream& operator>>(int& value) {

      // buffer -> EOF + FAIL
      if (m_buffer.empty()) {
        m_state |= StreamBits::eofbit;
        m_state |= StreamBits::failbit;
        return *this;  // MyStream object திரும்பும்
      }

      try {

        std::size_t characters_read {}; // stoi எத்தனை chars படித்தது

        // string → int மாற்றுகிறது
        // characters_read-இல் எத்தனை chars படித்தோம் என்று சேமிக்கிறது
        value = std::stoi(m_buffer, &characters_read);

        // படித்த பகுதியை buffer-இல் இருந்து நீக்கு
        // "10 20 30" → substr(2) → " 20 30"
        m_buffer = m_buffer.substr(characters_read);

        // முன்னால் உள்ள இடைவெளிகளை நீக்கு
        // " 20 30" → "20 30"
        while (!m_buffer.empty() && m_buffer[0] == ' ')
            m_buffer = m_buffer.substr(1);
      }
      catch (...) {
        m_state |= StreamBits::failbit;
      }

      return *this;
    }    
    // ─────────────────────────────────────
    // Stream நிலை print செய்ய
    // ─────────────────────────────────────
    void print_state() const {

      std::cout << "good(): " << good() << '\n';
      std::cout << "eof(): " << eof() << '\n';
      std::cout << "fail(): " << fail() << '\n';
      std::cout << "bad(): " << bad() << '\n';

    }

    // buffer current state
    void print_buffer() const {
      std::cout << "buffer: \"" << m_buffer << "\"\n";
    }
};

// ─────────────────────────────────────────
// fill_vector போன்று - numbers படித்து
// loop நின்றதற்கான காரணம் கண்டுபிடிக்கிறது
// ─────────────────────────────────────────

void read_numbers(MyStream& stream) {

    int value {};

    // operator>> → MyStream& return
    // operator bool() → good() சோதிக்கிறது
    // good() false → loop நிற்கிறது 
    while (stream >> value)
        std::cout << "Read: " << value << '\n';

    // loop நின்றது ஏன்?
    // eof() முதலில் சோதிக்க வேண்டும் - ஏனென்றால்
    // EOF hit ஆனால் eofbit + failbit இரண்டும் set ஆகும்
    if (stream.eof()) {
      std::cout << "[INFO] Buffer empty - EOF\n";
      return;
    }        

    if (stream.fail()) {
      std::cout << "[INFO] int அல்லாத character\n";
    }
}

// ----------------------------------------
// MAIN
// ------------------------------------------

int main() {

  // Case 1: normal EOF
  std::cout << "=== Case 1: EOF ===\n";
  {
    MyStream stream { " 10 20 30" };
    read_numbers(stream);
    std::cout << '\n';
    stream.print_state();
  }

  // Case 2: int character
  std::cout << "\n=== Case 2: character ===\n";
  {
    MyStream stream { "10 20 hello" };
    read_numbers(stream);
    std::cout << '\n';
    stream.print_state();
  }

  // Case 3: clear() 
  std::cout << "\n=== Case 3: clear() ===\n";
  {
    MyStream stream { "10 20 hello" };

    int value {};
    stream >> value; std::cout << "Read: " << value << '\n';
    stream >> value; std::cout << "Read: " << value << '\n';
    stream >> value; // hello didn't work

    std::cout << "\nclear() before:\n";
    stream.print_state();

    stream.clear();

    std::cout << "\nclear() After:\n";
    stream.print_state();
  }

  return 0;
}
constexpr int badbit = 0b0100;