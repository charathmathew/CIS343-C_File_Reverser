#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include<stdio.h>

int read_file(char* filename, char **buffer);
int write_file(char* filename, char *buffer, int size);

#endif
