#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>

// p155 print size submission block etc... same with ls -als

void printStat(char* filename, struct stat*);
char getType(struct stat*);
char* getPermission(struct stat*);

int main(int argc, char* argv[])
{
	DIR* dp;
	struct dirent* dent;
	struct stat st;
	char* dir;
	char path[BUFSIZ + 1];

	if(argc == 1)
		dir = ".";
	else
		dir = argv[1];
	
	if((dp = opendir(dir)) == NULL)
	{
		perror(dir);
		exit(1);
	}

	while((dent = readdir(dp)) != NULL)
	{
		sprintf(path, "%s/%s", dir, dent->d_name);
		if(lstat(path, &st) < 0)
			perror(path);
		else
			printStat(path, dent->d_name, &st);
	}
	closedir(dp);
	exit(0);
}

void printStat(char* filename, struct stat* st)
{
	printf(" %ld", st->st_blocks);
	//printf(" %s%s", getType(st->st_mode), getPermission(st->st_mode));
	printf(" %ld", st->st_nlink);
	printf(" %s", getpwuid(st->st_uid)->pw_name);
	printf(" %s", getgrgid(st->st_gid)->gr_name);
	printf(" %ld", st->st_size);
	printf(" %ld", st->st_ctime);
	printf(" %s\n", filename);
}
