/**************************************************************
* This file contains functions that perform
* file utilities
*
* @author Mathew Charath
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/*************************************************************
* Function that reads data from a file into a memory buffer
* 
* @param filename the file to read from
* @param buffer an allocated memory location
* @return numBytes number of bytes read into the memory buffer
*************************************************************/
int read_file(char* filename, char **buffer){

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

/*************************************************************
* Function that writes the data in the memory buffer into
* the output file
*
* @param filename name of the output file
* @param buffer memory buffer containing the data
* @param size size of the contents to be written
* @return numBytes number of bytes written onto the file
*************************************************************/
int write_file(char* filename, char *buffer, int size){

  FILE* outputfile = fopen(filename, "w");

  //TODO: find out how to use fwrite to write
  //to the outputfile
  int numBytes = fwrite(buffer, size, 1, outputfile);
  fclose(outputfile);

  return numBytes;
}
