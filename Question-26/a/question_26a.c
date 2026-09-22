#include <stdio.h>
#include <unistd.h>

int main()
{
    execl("/bin/ls", "ls", "-R", "-l", NULL);

    perror("execl");
    return 1;
}
