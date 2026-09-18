#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat file;

    if (stat("testfile.txt", &file) == -1) {
        perror("stat");
        return 1;
    }

    printf("File size: %ld bytes\n", file.st_size);

    return 0;
}
