#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // Open existing file in read-write mode
    fd = open("existing.txt", O_RDWR | O_CREAT | O_EXCL, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("File opened successfully\n");
    printf("File descriptor: %d\n", fd);

    close(fd);

    // Try O_EXCL
    fd = open("existing.txt", O_RDWR | O_EXCL);

    if (fd == -1)
        perror("O_EXCL");
    else {
        printf("O_EXCL: File opened successfully\n");
        close(fd);
    }

    return 0;
}
