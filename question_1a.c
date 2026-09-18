#include <stdio.h>
#include <unistd.h>

int main() {
    int result;

    result = symlink("original.txt", "softlink.txt");

    if (result == 0)
        printf("Soft link created successfully.\n");
    else
        perror("symlink");

    return 0;
}