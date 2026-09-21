#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Process ID: %d\n", getpid());
    fflush(stdout);

    while (1)
    {
        sleep(1);
    }

    return 0;
}
