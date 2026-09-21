#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Process ID: %d\n", getpid());
    fflush(stdout);

    while (1)
    {
        // Busy loop keeps the process running
    }

    return 0;
}
