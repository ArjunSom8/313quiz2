#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void print_file_type(const char *path) 
{
    struct stat file_stat;
    
    if (lstat(path, &file_stat) == 0) 
    {
        if (S_ISREG(file_stat.st_mode)) 
        {
            printf("%s: regular file\n", path);
        } 
        else if (S_ISDIR(file_stat.st_mode)) 
        {
            printf("%s: directory\n", path);
        } 
        else if (S_ISLNK(file_stat.st_mode)) 
        {
            printf("%s: symbolic link\n", path);
        } 
        else if (S_ISCHR(file_stat.st_mode)) 
        {
            printf("%s: character special file\n", path);
        } 
        else if (S_ISBLK(file_stat.st_mode)) 
        {
            printf("%s: block special file\n", path);
        }
        else if (S_ISFIFO(file_stat.st_mode))
        {
            printf("%s: FIFO special file\n", path);
        } 
        else if (S_ISSOCK(file_stat.st_mode))
        {
            printf("%s: socket special file\n", path);
        }
        else 
        {
            printf("%s: unknown file type\n", path);
        }
    } 
    else 
    {
        perror(path);
    }
}

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("usage: %s path1 [path2 ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) 
    {
        print_file_type(argv[i]);
    }

    return 0;
}
