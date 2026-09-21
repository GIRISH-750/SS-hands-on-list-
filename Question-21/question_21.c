#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    pid_t pid;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        close(fd);
        return 1;
    }
    else if (pid == 0)
    {
        write(fd, "Written by Child\n", 17);
    }
    else
    {
        write(fd, "Written by Parent\n", 18);
    }

    close(fd);

    return 0;
}
