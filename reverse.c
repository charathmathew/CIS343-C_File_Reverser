#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int main(int argc, char** argv){
  if(argc != 3){
    printf("An input and output file must be specified\n");
    exit(0);
  }
  else{
    char* input_filename = argv[1];
    char* output_filename = argv[2];
    char* buffer;

    FILE* inputfile = fopen(input_filename, "r");
    //FILE* outputfile = fopen(output_filename, "w");

    //TODO: error check for FILE opening

    //find size of the input file
    //code provided by Professor Woodring
    struct stat st;
    stat(input_filename, &st);
    int size = st.st_size;

    //print the input file size
    printf("The input file size: %d\n", size);

    fclose(inputfile);
    //allocate memory to store the contents of the file
    buffer = (char*) malloc(sizeof(char) * size);

    //TODO: error check the above malloc operation

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
    printf("The file has been reversed\n");
  }
}
