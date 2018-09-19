#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/******************************************************************
* Main function for a program that writes the reversed contents
* of a file to an output file using the file utilities defined in
* file_utilites.h and implemented in file_utilites.c
*
* @author Mathew Charath
******************************************************************/
int main(int argc, char** argv){
  if(argc != 3){
    printf("Incorrect Exceution!\n");
    printf("An input and output file must be specified\n");
    exit(0);
  }
  else{
    //input file
    char* input_filename = argv[1];
    //output file
    char* output_filename = argv[2];

    //memory buffer
    char* buffer;

    FILE* inputfile = fopen(input_filename, "r");

    //TODO: error check for FILE opening
    if(inputfile == NULL){
      fprintf(stderr, "Error opening file...\n");
      exit(0);
    }

    //find size of the input file
    //code provided by Professor Woodring
    struct stat st;
    stat(input_filename, &st);
    int size = st.st_size;

    fclose(inputfile);

    //read the contents of the file into
    //the allocated memory buffer
    int numBytesRead = read_file(input_filename, &buffer);

    //TODO: error check if numBytesRead is <= 0

    //reverse the contents of the buffer
    char* reversedBuffer = (char*) malloc(sizeof(char) * size);
    for(int i = 0; i < size; i++){
      reversedBuffer[i] = buffer[size-1 - i];
    }

    //TODO: error check for the buffer reversal

    //write the reversedBuffer to the outputfile
    int numBytesWritten = write_file(output_filename, reversedBuffer, size);

    //TODO: error check for if numBytesWritten is <= 0

    free(buffer);
    free(reversedBuffer);
  }
}
