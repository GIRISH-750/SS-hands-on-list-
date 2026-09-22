#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>

int main()
{
    pid_t pid;
    int fd;
    time_t current_time;
    time_t target_time;

    /* Create child process */
    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
    {
        printf("Daemon started with PID: %d\n", pid);
        return 0;
    }

    /* Create new session */
    if (setsid() == -1)
    {
        perror("setsid");
        return 1;
    }

    /* Change working directory */
    chdir("/tmp");

    /* Close standard file descriptors */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    /* Execute task after 10 seconds */
    current_time = time(NULL);
    target_time = current_time + 10;

    while (time(NULL) < target_time)
    {
        sleep(1);
    }

    /* Write task result to file */
    fd = open("/tmp/daemon_task.txt",
              O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1)
        exit(1);

    dprintf(fd, "Task executed by daemon at %ld\n", time(NULL));

    close(fd);

    return 0;
}
