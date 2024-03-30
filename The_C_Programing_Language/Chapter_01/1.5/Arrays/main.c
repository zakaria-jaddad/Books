#include <stdio.h>

int main(void)
{
    int c, i, nwhite, nother;
    int ndigit[10];

    // set 0 to each digit
    nwhite = nother = 0;
    for (int i = 0; i < 10; ++i)
    {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        // checks if c is a number
        if (c >= '0' && c <= '9')
        {
            // c - '0' to get c value
            ++ndigit[c - '0'];
        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }

    // print output
    printf("digits: ");
    for (int i = 0; i < 10; ++i)
    { // i++ and ++i here is the same thing
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n",
           nwhite, nother);
}