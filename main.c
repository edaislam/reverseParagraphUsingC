#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//prepared by Eda İslam
//Code that reverses the 'paragraph' and not only word
//in order to reverse the paragraph the code detects last new line character as the end of the paragraph (it stops reading the paragraph if the last line is empty)
//for example if your input is 'metuor' then you should press enter twice one fore showing the line is empty and one for seeing the result

void reverseString(char* );  //function prototype

int main() {
    char* paragraph = NULL;   //store th paragraph using pointer
    char buffer[100];         //buffer to read each line
    size_t paragraph_size = 0;    //paragraph has 0 length at the start
    size_t len;                   //length of every character

    printf("Enter a paragraph: ");

    //loop tp read the input line by line
    while (fgets(buffer, sizeof(buffer), stdin)) {
        len = strlen(buffer);
        //if line is empty
        if (len == 1 && buffer[0] == '\n') {
            break;   //stop reading after a single newline character
        }

        //resize the memory block that paragraph pointer points
        char *temp = realloc(paragraph, paragraph_size + len + 1);  //+1 for the null character
        if (!temp) {  //error if the reallocation has failed
            free(paragraph);
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        paragraph = temp;

        // Copy the buffer into the paragraph
        strcpy(paragraph + paragraph_size, buffer);
        paragraph_size += len;
    }

    if (paragraph) {
        reverseString(paragraph);  //reverse the paragraph
        printf("The reversed string is:%s", paragraph );
    } else {
        printf("\nNo paragraph entered.\n");
    }

    free(paragraph); // Free the allocated memory
    return 0;
}

void reverseString(char* str){
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while (start < end){

        //swap characters
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        //move pointers
        start++;
        end--;
    }
}