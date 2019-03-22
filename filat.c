#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <systypes.h>
#include <sys/stat.h>

int main (int argc, char*argv[])
{
	struct stat attributes;
	if (argc != 2)return 1;

	lstat(argv[1],&attributes);

	printf("-------------------------%s----------------------------",argv[1]);

	printf("%-20s:","Access privileges");
	printf((S_ISDIR(attributes.st_mode))? "d" : "-");
	printf((attributes.st_mode & S_IRUSR) ? "r" : "-");
	printf((attributes.st_mode & S_IWUSR) ? "w" : "-");
	printf((attributes.st_mode & S_IXUSR) ? "x" : "-");
	printf((attributes.st_mode & S_IRGRP) ? "r" : "-");
	printf((attributes.st_mode & S_IWGRP) ? "w" : "-");
	printf((attributes.st_mode & S_IXGRP) ? "x" : "-"); 
	printf((attributes.st_mode & S_IROTH) ? "r" : "-");
	printf((attributes.st_mode & S_IWOTH) ? "w" : "-");
	printf((attributes.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n");

	printf("%-20s: %s", "last acces",ctime(&attributes.st_atime));
	printf("%-20s: %s", "last modification", ctime(&attributes.st_mtime));
	printf("%-20s: %s", "last inode change", ctime(&attributes.st_ctime);

	return 0;
}
