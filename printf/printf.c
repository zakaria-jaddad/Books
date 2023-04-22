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
        // * if the user didn't press enter, add place for the new char 
        COUNTER++;
    }


    print("\n", 19, 65, 59);
    return 0;
    free(buffer);


}

void print(const char *buffer, ...) {

    va_list args;
    va_start(args, buffer);


    // TODO : iterrating over the string  
    for (int i = 0; buffer[i] != '\0' ; i++) {

        // * if ther is the % sympole
        if (buffer[i] == '%') {
            
            // TODO : handeling %d DONE
            if(buffer[i + 1] == 'd'){

                // ! adding 1 to pass the next d
                i++;

                // * getting the value of the integer argument 
                int num = va_arg(args, int);

                // * allocating memory for the ascii string 
                char *number = malloc(sizeof num);

                // * conveting int number to ascii value 
                sprintf(number, "%d", num);

                write(1, number, strlen(number));
            }
        }
        else
            write(1, &buffer[i], 1);

    }
    // write(1, buffer, strlen(buffer));
}