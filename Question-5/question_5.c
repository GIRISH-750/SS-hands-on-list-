#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd[5];

    fd[0] = creat("file1.txt", 0644);
    fd[1] = creat("file2.txt", 0644);
    fd[2] = creat("file3.txt", 0644);
    fd[3] = creat("file4.txt", 0644);
    fd[4] = creat("file5.txt", 0644);

    printf("Process ID: %d\n", getpid());

    printf("FDs: %d %d %d %d %d\n",
           fd[0], fd[1], fd[2], fd[3], fd[4]);

    while (1) {
        sleep(1);
    }

    return 0;
}
