#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"
#include <sys/stat.h>

int read_file(char* filename, char **buffer){
  /*
  -read the data into the allocated memory buffer
  */

  FILE* inputfile = fopen(filename,"r");

  //find the size of the file
  //code provided by professor Woodring
  struct stat st;
  stat(filename, &st);
  int size = st.st_size;

  *buffer = (char*) malloc(sizeof(char) * size);

  //TODO: find out how to use fread to read
  //the file into memory buffer
  int numBytes = fread(*buffer, size, 1, inputfile);

  fclose(inputfile);

  return numBytes;
}

int write_file(char* filename, char *buffer, int size){

  FILE* outputfile = fopen(filename, "w");

  //TODO: find out how to use fwrite to write
  //to the outputfile
  int numBytes = fwrite(buffer, size, 1, outputfile);
  fclose(outputfile);

  return numBytes;
}
