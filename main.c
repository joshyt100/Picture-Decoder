#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// Function to perform bitwise exclusive-or operation
void xorOperation(char *line, char *key) {
    int i;
    for (i = 0; i < strlen(line); i++) {
        line[i] = (line[i] == '1' && key[i] == '1') || (line[i] == '0' && key[i] == '0') ? '0' : '1';
    }
}
//Function to perform left rotate
void rotateLeft(char* arr, int size, int n)
{
  char *temp = (char*)calloc(size+1, sizeof(char));
  int shift = n % size;
  int i = 0;
  for (i = 0; i < size; i++){
    int other_index  = (i + shift) % size;
    temp[i] = arr[other_index];

  }
  strncpy(arr,temp,size);
  free(temp);
  

}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: decoder file\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r"); // open file
    if (fp == NULL) {
        printf("Unable to open input file\n");
        return 1;
    }

    // Read the decoding key
    char key[1001]; // Maximum width of the image
    fgets(key, sizeof(key), fp);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character

    // Initialize the stack
    Stack *stack = createStack();

    // Read and process each line
    int line_num = 0; 
    char image_array[1001];    

    while (fgets(image_array, sizeof(image_array), fp) != NULL) {
        
        image_array[strcspn(image_array, "\n")] = '\0'; // Remove newline character
        int size = strlen(image_array);
        xorOperation(image_array, key);
        rotateLeft(image_array,size, line_num);
        push(stack, image_array);
        line_num++;
        memset(image_array, 0, sizeof image_array); // set contents of array to 0
    }

    // Print the decoded image
    while (!isEmpty(stack)) {
        char *line = pop(stack);
        int i = 0;
        for ( i = 0; i < strlen(line); i++) {
            printf("%c", line[i] == '1' ? 'X' : ' ');
        }
        printf("\n");
        free(line);
    }

    fclose(fp);
    destroyStack(stack);

    return 0;
}

