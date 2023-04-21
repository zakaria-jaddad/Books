#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

    // ! write(int __fd, const void * __buf, size_t __nbyte)

// void print() {

// }

int main(void) {
    // TODO : Get the buffer from the user 
    char *buffer = NULL;
    int COUNTER = 0;

    // * Giving prompt to the user 
    printf("Write Something Here : \n");

    // * scaning the buffer 
    while(1) {

        // * adding one byte every time the user add a char 
        buffer = realloc(buffer, (COUNTER + 1) * sizeof(char));

        // * storing a char to the buffer 
        scanf("%c", &buffer[COUNTER]);

        // * if the user pressed enter to end the string  
        if (buffer[COUNTER] == '\n') {
            // * switch \n to null operator
            buffer[COUNTER] = '\0';
            break;
        }
        // * if the user didn't press enter add anoter place for the new char 
        COUNTER++;
    }


    printf("%s \n %d", buffer, COUNTER);
    return 0;
    free(buffer);
    // print()
}