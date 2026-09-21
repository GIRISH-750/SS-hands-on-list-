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

    struct flock lock;
    int record_no = 2;

    fd = open("records.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    /* Create 3 records */
    write(fd, records, sizeof(records));

    /* Lock record 2 */
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_no - 1) * sizeof(struct record);
    lock.l_len = sizeof(struct record);
    lock.l_pid = getpid();

    printf("Trying to lock record %d...\n", record_no);

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Write lock acquired on record %d.\n", record_no);

    /* Go to record 2 */
    lseek(fd, lock.l_start, SEEK_SET);

    read(fd, &records[1], sizeof(struct record));

    printf("Before modification: %d %s\n",
           records[1].id, records[1].name);

    /* Modify record 2 */
    snprintf(records[1].name, sizeof(records[1].name), "UpdatedBob");

    lseek(fd, lock.l_start, SEEK_SET);
    write(fd, &records[1], sizeof(struct record));

    printf("Record %d modified.\n", record_no);

    /* Unlock */
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);

    return 0;
}
