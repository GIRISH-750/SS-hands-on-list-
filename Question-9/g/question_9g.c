#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat file;

    if (stat("testfile.txt", &file) == -1) {
        perror("stat");
        return 1;
    }

    printf("Number of blocks: %ld\n", file.st_blocks);

    return 0;
}
