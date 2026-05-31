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

       
}