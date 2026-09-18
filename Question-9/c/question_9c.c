#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat file;

    if (stat("testfile.txt", &file) == -1) {
        perror("stat");
        return 1;
    }

    printf("UID: %d\n", file.st_uid);

    return 0;
}
