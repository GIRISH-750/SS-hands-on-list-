#include <stdio.h>
#include <sys/stat.h>

int main() {
    if (mkfifo("myfifo2", 0666) == 0)
        printf("FIFO created successfully\n");
    else
        perror("mkfifo");

    return 0;
}
