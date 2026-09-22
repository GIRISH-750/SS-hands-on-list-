#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
    execle("/bin/ls", "ls", "-R", "-l", NULL, environ);

    perror("execle");
    return 1;
}
