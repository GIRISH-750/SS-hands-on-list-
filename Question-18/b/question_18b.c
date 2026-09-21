#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct record {
    int id;
    char name[20];
};

int main() {
    int fd;
    struct record records[3] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };

    struct record record;
    struct flock lock;
    int record_no = 2;

    open("../records.txt", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;    }

    /* Create 3 records */
   

    /* Lock record 2 for reading */
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_no - 1) * sizeof(struct record);
    lock.l_len = sizeof(struct record);
    lock.l_pid = getpid();

    printf("Trying to lock record %d for reading...\n", record_no);

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Read lock acquired on record %d.\n", record_no);

    lseek(fd, lock.l_start, SEEK_SET);

    read(fd, &record, sizeof(struct record));

    printf("Record: %d %s\n", record.id, record.name);

    /* Unlock */
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);

    return 0;
}
