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
       MyOfstream(const char* filement) {
          
           fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644 );

           std::cout << "[OPEN FOR WRITE]\n";
           std::cout << "fd : " << fd << '\n';
       }   

       MyOfstream& operator<<(const char* text) {
          
          std::cout << *this <<"[WRITE]\n";

          write(fd,text,strlen(text));

          return *this;
       }

       MyOfstream& operator<<(int value) {

           char buffer[100];

           snprintf(buffer, sizeof(buffer), "%d",value);
       }
}