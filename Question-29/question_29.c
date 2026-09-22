#include <stdio.h>
#include <unistd.h>
#include <sched.h>

void print_policy(int policy)
{
    if (policy == SCHED_OTHER)
        printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO)
        printf("SCHED_FIFO\n");
    else if (policy == SCHED_RR)
        printf("SCHED_RR\n");
    else
        printf("Unknown policy\n");
}

int main()
{
    int policy;
    struct sched_param param;

    /* Get current scheduling policy */
    policy = sched_getscheduler(0);

    if (policy == -1)
    {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy: ");
    print_policy(policy);

    /* Set SCHED_FIFO */
    param.sched_priority = 10;

    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1)
    {
        perror("sched_setscheduler");
        return 1;
    }

    /* Get policy again */
    policy = sched_getscheduler(0);

    if (policy == -1)
    {
        perror("sched_getscheduler");
        return 1;
    }

    printf("New scheduling policy: ");
    print_policy(policy);

    return 0;
}
