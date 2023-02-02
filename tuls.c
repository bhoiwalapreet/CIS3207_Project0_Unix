#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


void listFiles(const char *dirname);

int main(int argc, char *argv[]) {
    char *dirname = ".";
    // initialized to current directory if the number of command-line arguments (argc) is <= 1
    // Otherwise, dirname is set to the value of the first command-line argument argv[1] (what the user passes)
    if (argc > 1) {
        dirname = argv[1];
    }
    //calling the function and passing the directory in
    listFiles(dirname);

    return 0;
}

void listFiles(const char *dirname) {
    DIR *dir = opendir(dirname);
    //open the specified directory and if not possible the print an error message
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    //starting to read files in the directory now
    printf("Reading files in: %s\n", dirname);
    //code to iterate through the directory and prints the name of each file in the directory.
    struct dirent *entity;
    entity = readdir(dir);
    while (entity != NULL) {
        printf("%s/%s\n", dirname, entity->d_name);
        entity = readdir(dir);
    }
    closedir(dir);
}


//path
// /Users/preetbhoiwala/Desktop/School/Spring 2023/CIS3207_OperatingSystems/Labs/Lab1_UnixUtilities

