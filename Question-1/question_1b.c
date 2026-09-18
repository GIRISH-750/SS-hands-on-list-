#include <stdio.h>
#include <unistd.h>

int main() {
    if (link("original.txt", "hardlink2.txt") == 0)
        printf("Hard link created successfully\n");
    else
        perror("link");

    return 0;
}

