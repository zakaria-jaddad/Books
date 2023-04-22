#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

    // ! write(int __fd, const void * __buf, size_t __nbyte)

    // * functions 
void print(const char *buffer, ...);

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


    // print(buffer, 44, 45);
    // print("Ana Zakria This Is Just Some Test Here\n");
    print("Salam ana Zakaria 3andi %d l3am lwalid 3ando %d l3am \n", 19, 56);
    return 0;
    free(buffer);
    // print()
}

void print(const char *buffer, ...) {

    va_list args;
    va_start(args, buffer);

    int little_counter = -1;

    // TODO : iterrating over the string  
    for (int i = 0; buffer[i] != '\0' ; i++) {

        // * if ther is the % sympole
        if (buffer[i] == '%') {
            
            // TODO : handeling %d
            if(buffer[i + 1] == 'd'){
                little_counter = i + 1;
                char number[100];
                int num = va_arg(args, int);
                sprintf(number, "%d", num);
                write(1, number, strlen(number));
            }
        }
        else if (i != little_counter)
            write(1, &buffer[i], 1);

    }
    // write(1, buffer, strlen(buffer));
}