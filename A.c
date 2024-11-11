Q.1) Write a C program to find whether a given file passed through command line arguments are present in current directory or not.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    if (argc < 2) {
        printf("Usage: %s <filename1> <filename2> ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &fileStat) == 0) {
            printf("File '%s' is present in the current directory.\n", argv[i]);
        } else {
            printf("File '%s' is NOT present in the current directory.\n", argv[i]);
        }
    }

    return 0;
}


Output:
File 'testfile.txt' is present in the current directory.
File 'image.jpg' is NOT present in the current directory.

