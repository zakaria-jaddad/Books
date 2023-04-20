#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *hello = malloc(20 * sizeof(char));
    printf("Write Some Thing Here : \n");
    scanf("%[^\n]", hello);

    // ? printing using the address of a pointer    
    printf("this is what you just typed %s \n", hello);
    return 0;
}