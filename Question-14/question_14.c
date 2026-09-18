#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat file;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (lstat(argv[1], &file) == -1) {
        perror("lstat");
        return 1;
    }

    if (S_ISREG(file.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(file.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(file.st_mode))
        printf("Symbolic link\n");
    else if (S_ISFIFO(file.st_mode))
        printf("FIFO (named pipe)\n");
    else if (S_ISCHR(file.st_mode))
        printf("Character device\n");
    else if (S_ISBLK(file.st_mode))
        printf("Block device\n");
    else if (S_ISSOCK(file.st_mode))
        printf("Socket\n");
    else
        printf("Unknown file type\n");

    return 0;
}
