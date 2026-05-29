#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

// ===============================================
// SIMPLE OFSTREAM
// ===============================================

class MyOfstream {

    private:
       int fd;

    public:
       MyOfstream(const char* filename) {
          
           fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644 );

           std::cout << "[OPEN FOR WRITE]\n";
           std::cout << "fd : " << fd << '\n';
       }   

       MyOfstream& operator<<(const char* text) {
          
          std::cout  <<"[WRITE]\n";

          write(fd,text,strlen(text));

          return *this;
       }

       MyOfstream& operator<<(int value) {

           char buffer[100];

           snprintf(buffer, sizeof(buffer), "%d",value);

           write(fd, buffer, strlen(buffer));

           return *this;
       }

       ~MyOfstream() {

           std::cout << "[CLOSE WRITE FILE]\n";

           close(fd);
       }
};

// ===========================================
// SIMPLE IFSTREAM
// ============================================

class MyIfstream {

    private:
       int fd;

    public:
      MyIfstream(const char* filename) {

          fd = open(filename, O_RDONLY);

          std::cout << "[OPEN FOR READ]\n";

          std::cout << "fd : " << fd << '\n';
      }   

      void read_all() {

        char buffer[1024];;

        ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);

        if (bytes > 0) {

            buffer[bytes] = '\0';

            std::cout << "[FILE CONTENT]\n";
            std::cout << buffer << '\n';
        }
      }

      ~MyIfstream() {

        std::cout << "[CLOSE READ FILE]\n";

        close(fd);
      }
};

// ===========================================
// Main
// ===========================================

int main() {
    {

    MyOfstream fout("person.txt");

    fout << "Name : Tony Stark\n";

    fout << "Age : ";

    fout << 45;

    fout << "\n";
}
{
    MyIfstream fin("person.txt");

    fin.read_all();
}
}

/*
 ./a.out
[OPEN FOR WRITE]
fd : 3
[WRITE]
[WRITE]
[WRITE]
[CLOSE WRITE FILE]
[OPEN FOR READ]
fd : 3
[FILE CONTENT]
Name : Tony Stark
Age : 45

[CLOSE READ FILE]
*/