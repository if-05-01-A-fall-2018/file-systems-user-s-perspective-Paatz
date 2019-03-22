#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char *argv[])
{
	char buff[6000];
	printf("First arg: %s\n", argv[1]);
	int fd = open(argv[1], O_RDONLY);
	int newF = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	int run = 1;
	prinf("%d\n", fd);
	while(run)
	{
		int tmp = read(fd, &buff, 6000)
		if(tmp == 0)
		{
			run = 0;
		}
		write(newF, &buff,tmp);
	}
	return 0;
}
