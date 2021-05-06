#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void printStat(char* filename, struct stat*);
void printType(mode_t);
void printPermission(mode_t);

int main(int argc, char* argv[])
{
        DIR* dp;
        char* dir;
        char root[2] = ".";
        struct stat st;
        struct dirent* dent;
        char path[BUFSIZ + 1];

        if(argc == 1)
                dir = root;
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
                        printStat(dent->d_name, &st);
        }

        closedir(dp);
        exit(0);
}

void printStat(char* filename, struct stat* st)
{
        printf(" %5ld ", st->st_blocks);
        // printf(" %c%s", printType(st->st_mode), printPermission(st->st_mode));
        printType(st->st_mode);
        printPermission(st->st_mode);
        printf(" %3ld", st->st_nlink);
        printf(" %s", getpwuid(st->st_uid)->pw_name);
        printf(" %s", getgrgid(st->st_gid)->gr_name);
        printf(" %9ld", st->st_size);
        printf(" %.12s", ctime(&st->st_mtime)+4);
        printf(" %s", filename);

        if(S_ISDIR(st->st_mode))
                putchar('/');
        putchar('\n');
}

void printType(mode_t mode)
{
        if(S_ISREG(mode))
                printf("-");
        else if(S_ISDIR(mode))
                printf("d");
        else if(S_ISCHR(mode))
                printf("c");
        else if(S_ISBLK(mode))
                printf("b");
        else if(S_ISLNK(mode))
                printf("l");
        else if(S_ISFIFO(mode))
                printf("p");
        else if(S_ISSOCK(mode))
                printf("s");
}

void printPermission(mode_t mode)
{
        char perm[10] = "---------";

        for(int i = 0; i < 3; i++)
        {
                if(mode & (S_IRUSR >> i*3))
                        perm[i*3] = 'r';
                if(mode & (S_IWUSR >> i*3))
                        perm[i*3 + 1] = 'w';
                if(mode & (S_IXUSR >> i*3))
                        perm[i*3 + 2] = 'x';
        }
        printf("%s", perm);
}

