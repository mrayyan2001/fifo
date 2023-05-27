#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

#define FIFO_PATH "/tmp/myfifo"

int main()
{
    if (mkfifo("myFifo1", 06666) == -1 && errno != EEXIST)
    {
        printf("Could not create fifo file.\n");
        return 1;
    }
    else
    {
        int fd = open("myFifo1", O_RDONLY);
        if (fd == -1)
        {
            return 3;
        }
        char y;
        if (read(fd, &y, sizeof(y)) == -1)
        {
            printf("Error Reading.");
            return 2;
        }
        printf("%c\n", y);
        close(fd);
    }

    return 0;
}