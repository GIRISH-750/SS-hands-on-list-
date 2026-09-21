#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc()
{
    unsigned int lo, hi;

    __asm__ volatile (
        "rdtsc"
        : "=a"(lo), "=d"(hi)
    );

    return ((uint64_t)hi << 32) | lo;
}

int main()
{
    uint64_t start, end;
    pid_t pid;

    start = rdtsc();

    pid = getpid();

    end = rdtsc();

    printf("PID: %d\n", pid);
    printf("Time taken by getpid(): %lu CPU cycles\n", end - start);

    return 0;
}
