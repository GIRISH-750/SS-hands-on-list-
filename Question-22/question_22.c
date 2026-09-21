#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child process exiting...\n");
        printf("Child PID: %d\n", getpid());

        exit(0);
    }
    else
    {
        printf("Parent process running...\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        sleep(30);
    }

    return 0;
}
