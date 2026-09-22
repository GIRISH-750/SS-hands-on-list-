#include <stdio.h>
#include <unistd.h>

int main()
{
    execlp("ls", "ls", "-R", "-l", NULL);

    perror("execlp");
    return 1;
}
