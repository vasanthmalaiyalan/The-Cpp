#include <iostream>
#include <string>

// ==========================================
//  Graphics library namespace
// ==========================================

namespace Graph_lib {

    class Text {

        public:
           void draw() {

              std::cout << "Drawing graphics text\n";
           }
    };

    class Line {

        public:
          void draw() {
            std::cout << "Drawing graphics line\n";
          }
    };
}

// =========================================
// Text processing namespace
// =========================================

namespace TextLib {

    class Text {

        public:
           void print() {
              std::cout << "Printing text document\n";
           }
    };

    class Line {

        public:
           void show() {
              std::cout << "Showing text line\n";
           }
    };
}

// ============================================
// Main
// ============================================

int main() {

    Graph_lib::Text graphics_text;
    Graph_lib::Line graphics_line;

    TextLib::Text document_text;
    TextLib::Line document_line;

    graphics_text.draw();
    graphics_line.draw();

    document_text.print();
    document_line.show();
}