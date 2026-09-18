#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    write(fd, "AAAAAAAAAA", 10);

    lseek(fd, 10, SEEK_CUR);

    write(fd, "BBBBBBBBBB", 10);

    close(fd);

    return 0;
}
