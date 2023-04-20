#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc == 1){
        printf("Write Something First");
        exit(1);
    }

    // ! this is a bit hard to understand at first here is what i have done
        // ! so char *argv[] is just a list of pointers having the address of the first char in the string 
        // * recall in C a STRING is just a pointer pointing to the first char 
        // * in other words the pointer stores the first char memory address
    // ! so here i used malloc for the memory inside it i give it the lenght of the argv array
    // ! then i multiplay it to a pointer of char 
        // ! so this will create a bunch of pointer depending on the value of argc each pointer pointing to a different memory address

    char **hello = malloc(argc * sizeof(char *));

    // * so this means that **hello is pointing to *hello and this *hello is an array of pointers each pointing to a differrent place of memory
    // ? Both *argv[] and **hello can be used to represent arrays of strings, and both can be accessed and manipulated using pointer arithmetic and array notation.

    memcpy(hello, argv, argc * sizeof(char *));

    for (int i = 1; i < argc; i++){
        printf("%s\n", hello[i]);
    }

    return 0;
}