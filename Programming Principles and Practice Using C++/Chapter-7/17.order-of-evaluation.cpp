#include <iostream>
#include <string>
#include <vector>

// ===========================================
// Global variables
// ============================================

std::string program_name = "demo";
std::vector<std::string> words;

// ======================================
// Function
// ======================================

void process() {

    std::string s;

    while (std::cin >> s && s != "quit") {

        std::string stripped;
        std::string not_letters;

        for (char x : s) {

            if (std::isalpha(x)) {

                stripped += x;
            }

            else {

                not_letter += x;
            }
        }

        words.push_back(stripped);

        std::cout << "stripped  : " << stripped << '\n';
        std::cout << "not_letter : " << not_letters << '\n';
    }

    std::cout << "Leaving process()\n";
}

// ==========================================
// Main
// ==========================================

int main() {

    std::cout << "Program started\n";

    process();

    std::cout << "Program ending\n"
}