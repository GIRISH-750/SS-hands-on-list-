#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;

    fd1 = open("testfile.txt", O_WRONLY | O_APPEND);

    if (fd1 == -1) {
        perror("open");
        return 1;
    }

    fd2 = fcntl(fd1, F_DUPFD, 0);

    if (fd2 == -1) {
        perror("fcntl");
        close(fd1);
        return 1;
    }

    write(fd1, "Written using fd1\n", 18);
    write(fd2, "Written using fd2\n", 18);

    close(fd1);
    close(fd2);

    return 0;
}
