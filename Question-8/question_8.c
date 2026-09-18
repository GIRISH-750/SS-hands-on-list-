#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd;
    char ch;

    fd = open("input.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    while (read(fd, &ch, 1) > 0) {
        write(1, &ch, 1);
    }

    close(fd);

    return 0;
}
