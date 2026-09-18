#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int flags;

    fd = open("testfile.txt", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    flags = fcntl(fd, F_GETFL);

    if (flags == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    if ((flags & O_ACCMODE) == O_RDONLY)
        printf("File is opened in READ ONLY mode\n");
    else if ((flags & O_ACCMODE) == O_WRONLY)
        printf("File is opened in WRITE ONLY mode\n");
    else if ((flags & O_ACCMODE) == O_RDWR)
        printf("File is opened in READ WRITE mode\n");

    close(fd);

    return 0;
}
