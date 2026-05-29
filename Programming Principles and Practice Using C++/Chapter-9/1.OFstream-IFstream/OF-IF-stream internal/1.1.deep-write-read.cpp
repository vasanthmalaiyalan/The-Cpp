#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main() {

    std::cout << "====================================\n";
    std::cout << "STEP 1 : OPEN FILE\n";
    std::cout << "======================================\n";

    int fd = open("person.txt", O_WRONLY | O_CREAT | O+TRUNC, 0644);

    std::cout << "open() return value (fd) : " << fd << '\n';
    std::cout << "\n=====================================\n";
    std::cout << "STEP 2 : WRITE FILE\n";
    std::cout << "========================================\n";

    const char* text = "Tony Stark";

    ssize_t bytes_written = write(fd,text,strlen(text));

    std::cout << "text                 : " << text << '\n';
    std::cout << "strlen(text)         : " << strlen(text) << '\n';
    std::cout << "write() return value : " << bytes_written << '\n';

    std::cout << "\n=====================================\n";
    std::cout << "STEP 3 : CLOSEE FILE\n";
    std::cout << "=======================================\n";

    int close_result = close(fd);

    std::cout << "close() return value : " << close_result << '\n';
    std::cout << "\n========================================\n";

    std::cout << "STEP 4 : OPEN AGAIN FOR READ\n";
    std::cout << "===========================================\n";

    fd = open("person.txt", O_RDONLY);

    std::cout << "open() return value (fd) : " << fd << '\n';

    std::cout << "\n===========================================\n";
    std::cout << "STEP 5 : READ FILE\n";
    std::cout << "==============================================\n";

    char buffer[100];

    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);

    buffer[bytes_read] = '\0';

    std::cout << "read() return value : " << bytes_read << '\n';
    std::cout << "buffer content      : " << buffer << '\n';

    std::cout << "\n============================================\n";
    std::cout << "STEP 6 : CLOSE FILE\n";
    std::cout << "==============================================\n";

    close_result = close(fd);

    std::cout << " close() return value : " << close_result << '\n';

    return 0;
}