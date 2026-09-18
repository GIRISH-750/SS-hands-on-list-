#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    off_t position;

    fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    write(fd, "AAAAAAAAAA", 10);

    position = lseek(fd, 10, SEEK_CUR);

    if (position == -1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("lseek return value: %ld\n", position);

    write(fd, "BBBBBBBBBB", 10);

    close(fd);

    return 0;
}

