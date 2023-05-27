#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (mkfifo("myFifo1", 06666) == -1 && errno != EEXIST)
    {
        printf("Could not create fifo file.\n");
        return 1;
    }
    else
    {
        int fd = open("myFifo1", O_WRONLY);
        if (fd == -1)
        {
            return 3;
        }
        char x = 'Z';
        if (write(fd, &x, sizeof(x)) == -1)
        {
            printf("Error writing.");
            return 2;
        }

        close(fd);
    }

    return 0;
}