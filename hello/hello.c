#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc == 1){
        printf("Write Something First");
        exit(1);
    }
    char *hello = malloc(strlen(argv[1]) * sizeof(char));
    // copying memory
    memcpy(&hello, &argv[1], sizeof(argv[1]));
    printf("%s", hello);
    return 0;
}