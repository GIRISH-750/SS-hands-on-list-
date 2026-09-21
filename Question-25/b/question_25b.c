#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing name program...\n");

    execl("./name", "name", "Girish", NULL);

    perror("execl");

    return 1;
}
