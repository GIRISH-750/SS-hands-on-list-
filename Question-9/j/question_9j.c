#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    struct stat file;

    if (stat("testfile.txt", &file) == -1) {
        perror("stat");
        return 1;
    }

    printf("Last change time: %s", ctime(&file.st_ctime));

    return 0;
}
