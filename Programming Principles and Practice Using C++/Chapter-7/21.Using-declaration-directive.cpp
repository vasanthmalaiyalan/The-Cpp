#include <iostream>
#include <string>
#include <vector>

// ==========================================
// Namespace
// ============================================

namespace Graphics {

    class Line {

    };
}

// ==========================================
// Using declarations
// ===========================================

using std::cout;
using std::cin;
using std::string;

// ========================================
// Main
// ========================================

int main() {

    string name;

    cout << "Please enter your name:\n";
    cin << name;
    cout << "Hello, " << name << '\n';

    // fully qualified name
    Graphics::Line line;
}