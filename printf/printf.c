#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <math.h>

    // ! write(int __fd, const void * __buf, size_t __nbyte)

// * functions 
int print(const char *buffer, ...);
void writeme(char *buffer);


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

    print(buffer);
    print("==========/ %f /=========", 6647352882635);
    return 0;
    free(buffer);


}

int print(const char *buffer, ...) {

    va_list args;
    va_start(args, buffer);


    // TODO : iterrating over the string  
    for (int i = 0; buffer[i] != '\0' ; i++) {

        // * if ther is the % sympole
        if (buffer[i] == '%') {
            
            // TODO : handeling %d DONE
            if(buffer[i + 1] == 'd') {

                // ! adding 1 to pass the next d
                i++;

                // * getting the value of the integer argument 
                int num = va_arg(args, int);

                // * allocating memory for the ascii string 
                char *number = malloc(sizeof num);

                // * conveting int number to ascii value 
                sprintf(number, "%d", num);

                writeme(number);
            }

            // TODO : handeling %s which is a string DONE 

            else if (buffer[i + 1] == 's') {

                i++;

                // * getting the string [buffer] value from the agruments 
                char *string = va_arg(args, char*);

                writeme(string);
            }

            // TODO : handeling %c which is a single char DONE 

            else if (buffer[i + 1] == 'c') {
                i++;

                char charcter = va_arg(args, int);

                write(1, &charcter, 1);
            }

            // TODO : handelign %f which is a floating point DONE

            else if (buffer[i + 1] == 'f') {
                i++;

                // ? checking 
                if (round(va_arg(args, double)) == 0)
                    perror("you forgot to add this | %f | in you're string");
                return errno;

                char *floating_number = malloc(sizeof(va_arg(args, double)));

                sprintf(floating_number, "%f", va_arg(args, double));

                writeme(floating_number);
            }

            // TODO : handeling %x hex and %o octal (4 bytes) value [int] DONE  

            else if (buffer[i + 1] == 'x' || buffer[i + 1] == 'X' || buffer[i + 1] == 'o') {
                char *hexoctal_number = malloc(sizeof(va_arg(args, int)));

                if (buffer[i + 1] == 'o')
                    sprintf(hexoctal_number, "%o", va_arg(args, int));
                else 
                    sprintf(hexoctal_number, "%x", va_arg(args, int));

                writeme(hexoctal_number);
                i++;
            }

            // TODO : handeling %lf, %lo, %lx, %ld (8 bytes) value double 

            else if (buffer[i + 1] == 'l') {

                long long_input_number = va_arg(args, long);
                char *float_octal_hex_int_number = malloc(sizeof(long_input_number));

                // * for float 
                if (buffer[i + 2] == 'f') {
                    double double_input_number = va_arg(args, double);
                    sprintf(float_octal_hex_int_number, "%lf", double_input_number);
                }
                // * for octal
                else if (buffer[i + 2] == 'o')
                    sprintf(float_octal_hex_int_number, "%lo", long_input_number);
                // * for hex 
                else if (buffer[i + 2] == 'x' || buffer[i + 2] == 'X')
                    sprintf(float_octal_hex_int_number, "%lx", long_input_number);
                // * for long
                else if (buffer[i + 2] == 'd')
                    sprintf(float_octal_hex_int_number, "%ld", long_input_number);

                writeme(float_octal_hex_int_number);
                i += 2;
            }
        }
        else
            write(1, &buffer[i], 1);
    }
    return 0;
}


// ! this is just a simple function to write the string i'm just too lazy to write it over and wover 

void writeme(char *buffer) {
    write(1, buffer, strlen(buffer));
}
