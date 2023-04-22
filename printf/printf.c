#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

    // ! write(int __fd, const void * __buf, size_t __nbyte)

    // * functions 
void print(char *buffer);

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

            // * realloctaign memory for \0
            buffer = realloc(buffer, (COUNTER + 1) * sizeof(char));

            // * switch \n to null operator
            buffer[COUNTER + 1] = '\0';
            break;
        }
        // * if the user didn't press enter add anoter place for the new char 
        COUNTER++;
    }


    print(buffer);
    print("Ana Zakria This Is Just Some Test Here\n");
    return 0;
    free(buffer);
    // print()
}

void print(char *buffer) {
    write(1, buffer, strlen(buffer));
}