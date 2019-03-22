#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <pwd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

char shortOfFile(mode_t mode);
char PremissionFromFile(mode_t mode);

int list_dir(const char* dirname)
{
	struct tm lt;
	struct passwd * pwd;
	struct stat my_stat;
	struct dirent* current_directory;

	DIR* directory = opendir(dirname);
	if(directory == NULL)
	{
		return 0;
	}

	printf("%s\n", dirname);
	printf("\n");

	current_directory = readdir(directory);
	while(current_directory)
	{
		stat(current_directory->d_name, &my_stat);

		if(!stat(current_directory->d_name, &my_stat))pwd= getpwuid(my_stat.st_uid);

		time_t t = my_stat.st_mtime;
		localtime_r(&t, &lt);	
		char timebuff[80];
		strftime(timebuff, sizeof(timebuff),"%c",&lt);
		if(pwd && current_directory->d_name[0] != '.'){
			printf("%s \t %c \t %s \t %s", my_stat.st_uid,(long)my_stat.st_size, timebuf, current_directory->d_name);
		printf("\n");
		current_directory = readdir(directory);		
		}
	closedir(directory);
	return 0;
	}

	int main(int argc, char* argv[])
	{
		if(argc == 1)return list_dir(".");

		return list_dir(argv[1]);
	}
	char shortOfFile(mode_t m){
	switch (mode & S_IFMT){
		case S_IFREG:
		return '-';
		case S_IFDIR:
		return 'd';
		case S_IFCHR:
		return 'c';
		case S_IFBLK:
		return 'b';
		case S_IFLNK:
		return 'l';
		case S_IFIFO:
		return 'f';
		case S_IFSOCK:
		return 's';
	
	}
	return '?';	
	}
	char* PremissionFromFile(mode_t mode);
	{
		char * prArr = (char*)malloc(sizeof(char)*10);
		prArr[0] = S_IRUSR ? 'r' : '-';
		prArr[1] = S_IWUSR ? 'w' : '-';
		prArr[2] = S_IXUSR ? 'x' : '-';
		prArr[3] = S_IRGRP ? 'r' : '-';
		prArr[4] = S_IWGRP ? 'w' : '-';
		prArr[5] = S_IXGRP ? 'x' : '-';
		prArr[6] = S_IROTH ? 'r' : '-';
		prArr[7] = S_IWOTH ? 'w' : '-';
		prArr[8] = S_IXOTH ? 'x' : '-';
		prArr[9] = '\0';
		return prArr;
	}
}








