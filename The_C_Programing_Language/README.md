# Chapter 01

## 1.1 Getting Started

The only way to learn a new programming language is by writing programs in it, so the first program we will write is the popular **Hello, World!** program

In the **C language** printing **"Hello, World!”** is like this 

```c
#include <stdio.h>
/*
- Book Explanation
	include information about standard library
  define a function called main
  that received no argument values
  statements of main are enclosed in braces
  main calls library function printf
  to print this sequence of characters
  \n represents the newline character
*/
int main() {
	printf("Hello, Wrold!\n");
}
```

The file that has the code should end with the ".c” extension, to run it depends on the system used for example there are `cc hello.c`, `gcc hello.c` or `clang hello.c` all this commands produce an executable file like this "a.out” or "hello”.

when it gets executed the "**Hello, World!**” will be printed in the terminal.

So A **C** program whatever it's size its size, consists only of functions, variables and the functions contain statements, so C is a functional language.

in the above example we have a function with the name `main` so the name main in **C** is a special, it is were the program start executing that means that every program must have a main function somewhere.

main usually call other functions to preform it's job, as you can see in the example above we have a `printf` function inside `main`, this function is not implemented in our example, so where is it?

In the top of our code there is the `#include <stdio.h>`  a header that tells the compiler to include information about the `Standard input/output library` where the `printf` function is defined and implemented.

Functions communicate and share data with each other using *arguments* inside `()`*,* in our `main` implementation we didn't provide any arguments to it.

A function can be called by using it's name and parentheses `printf()` , this function takes a lot of arguments but in out example it takes just the string **"Hello, World!”.**

The `\n` is a C notation of new line, it's *escape sequence character,* we will know more about those later, so `\n` informs `printf` to print a new line to understand it more we can implement the same Hello, World! program like this ways

```c
#include <stdio.h>

main() {
	printf("hello, ");  // no new line 
	printf("world!");    // no new line
	printf("\n");       // new line here
}
```

```c
#include <stdio.h>

main() {
	printf("hello, World!");  // no new line 
	printf("\n");       // new line here
}
```

Basically you can imaging a program that print each character it self then at the end prints new line, all would have the same output.

### Exercise 1-2.

Experiment to find out what happens when prints's argument string contains `\c`, where c is some character not listed above.

```c
#include <stdio.h>

int main(void) { 
	printf("Hello, world! \c\n");  // Waring here
}

```

This program give a compilation Warning for an unknown escape character `\c` 

## 1.2 Variables and Arithmetic Expressions

In the next program we will use the formula `oC=(5/9)(oF-32)` to print  Fahrenheit
temperatures and their Celsius equivalents like this 

```c
1   -17
20   -6
40    4
60   15
80   26
100  37
120  48
140  60
160  71
180  82
200  93
220 104
240 115
260 126
280 137
300 148
```

```c
#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
main() {
	int fahr, celsius;
	int lower, upper, step;
	
	lower = 0; /* lower limit of temperature scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	fahr = lower;
	
	while (fahr <= upper) {
		celsius = 5 * (fahr-32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
```

so let's break the code piece by piece.

- we know the `#iclude <stdio.h>` to import functions from the standard input/output
- we have the `/**/`  this sign is a comment when using it the compiler ignores whatever is written inside it, in this example it describes the purpose of the function
- `int fahr, celsius;` and `int lower, upper, step;` these are declaration statement in C all variables must be declared before they are used, usually at the beginning of the function
    - here the `int`  means that variables value must be of type Integer, this is important and here is why, when compiling the code by the compiler we need to specify what is the type of the variable to know how much memory the compiler should assign to it or allocate to it i don't know wish term should i use here
    - C provides several data types beside `int`  here are some of them
        - `char`: character a single byte
        - `short`: short integer
        - `long`: long integer
        - `double`: double-precision floating point
- `lower = 0; upper = 300; step = 20; fahr = lower;` those are assignment statements each variable will store a value `fahr` would get the value of `lower` which in this cast the value `0`
- for the `while loop code` the while loop has a condition statement and a body so
    - the condition is `(fahr <= upper)` every iteration the program check if `fahr` value is lower of equals to `upper` value if true the body will be executed if false the program continues executing other code
    - `printf` takes a weird string as a first argument let's break it down
        - `%d` is specified for printing integers in this case instead of getting %d we will get the value of fahr
        - `\t` is an escaping character stands for printing a tab which is 4 spaces.
    - notice in each iteration the fahr's value increments by the step value

```c
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
```

The output of the printf is not well organized we can solve that by doing this 

this prints the first number of each line in a field three digits wide, and the second in a field six
digits wide, like this.

```c
printf("%3d %6d\n", fahr, celsius);
/*
Output
  0   -17
 20    -6
 40     4
 60    15
 80    26
100    37
...
*/
```

If you know 0 F is actually about -17.8 C, to get more specific output we need to change the type of the variables in the example from `int` to `float` so that it can accept floating point numbers let's update it.

```c
#include <stdio.h>
/*
  Formula: oC=(5/9)(oF-32)
 */
int main(void)
{
  // declaration
  float fahr, celsius;
  float lower, upper, step;

  // assignment
  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper)
  {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
```

This still the same logic, changing types allows the formula for conversion to be written in a more natural way, remember in the previous example we hade the `int` data type we couldn't do the `5 / 9` operation because this would produce a floating point number and would lead to an compilation error. 

The `printf` conversion specification `%3.0f` specifies that `fahr` should be `foat` and to be printed at least three characters wide, with no decimal point and no fraction digit, instead for `celsius` which want to be printed at least 6 characters wide and 1 digit after the decimal point so the output would look like this: 

```c
  0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0

```

```c
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9

```

here are some examples of with and precision: 

| %d | print as decimal integer |
| --- | --- |
| %6d | print as decimal integer, at least 6 characters wide |
| %f | print as a floating point number  |
| %6f | print as a floating point number, at least 6 characters width |
| %.2f | print as a floating point number with 2 characters after decimal |
| %6.2f | print as a floating point number with 2 characters after decimal, at least 6 chars with  |
| %o | print as octal |
| %x | print as hex  |
| %c | print as char |
| %c | print as string |
| %% | print the symbol % |

There are more than these precisions.

### Exercise 1-3

Modify the temperature conversion program to print a heading above the table.

```c
#include <stdio.h>
/*
  Formula: oC=(5/9)(oF-32)
 */
int main(void)
{
  // declaration
  float fahr, celsius;
  float lower, upper, step;

  // assignment
  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  // print Heading above Table
  printf("Termpurature conversion program");

  
  while (fahr <= upper)
  {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f | %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
```

### Exercise 1-4

Write a program to print the corresponding Celsius to Fahrenheit table.

```c
#include <stdio.h>
/*
  Formula: F = C * (9 / 5) + 32
 */
int main(void) {

  // decaration
  float celsius, fahr;
  float lower, upper, step;

  // assignment
  lower = 0;
  upper = 300;
  step = 20; 

  printf("Termpurature conversion program from Celsuis to Fah.\n");
  
  while (celsius <= upper)
  {
    fahr = (celsius + 32) * (9.0 / 5.0);
    printf("fahr: %3.0f | celsius: %6.1f\n", fahr, celsius);
    celsius = celsius + step;
  }
}
```

## 1.3 The for statement

```c
#include <stdio.h>
/* print Fahrenheit-Celsius table */
main()
{
	int fahr;
	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
	printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

This example has the same output as the previous one.

but here we have used a for loop and we the conversion operation is inserted as an argument to `printf` .

The `for` statement is the same as the `while` loop but more cleaner where we don't need to think about the variables and updating them all operations happens inside the `()` , it contains three parts 

1. `fahr = 0` : this is the assignment of the initial value of the `fahr` inside the loop.
2. `fahr <= 300` : a condition that is evaluated if true the body of the loop get executed if false the body of it won't get executed
3. `fahr = fahr + 20` : here we want in each iteration the value of the `fahr` get incremented by 20

### Exercise 1-5

Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0.

```c
#include <stdio.h>
/*
  Formula: F = C * (9 / 5) + 32
 */
int main(void)
{

  // decaration
  float celsius, fahr;
  float lower, upper, step;

  // assignment
  lower = 0;
  upper = 300;
  step = 20;

  printf("Termpurature conversion program from Celsuis to Fah.\n");

  while (celsius <= upper)
  {
    fahr = (celsius + 32) * (9.0 / 5.0);
    printf("fahr: %3.0f | celsius: %6.1f\n", fahr, celsius);
    celsius = celsius + step;
  }
  printf("==========\n");

  
  for (int celsius = 300; celsius >= 0; celsius = celsius - 20)
  {
    printf("fahr: %3.0f | celsius: %6d\n", (celsius + 32) * (9.0 / 5.0), celsius);
  }
}
```

## 1.4 Symbolic Constants

So in the temperature program, it's bad practice to bury numbers inside the program like 300 and 20, one way to deal with this is to create `constants` using the `#define` key word, later if we want to change the value of the variable it’easy to change in just one place.

```c
#include <stdio.h>
#define LOWER 0 /* lower limit of table */
#define UPPER 300 /* upper limit */
#define STEP 20 /* step size */
/* print Fahrenheit-Celsius table */
main()
{
	int fahr;
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
	printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

so the `LOWER` `UPPER` are symbolic constants it's best practice to write them in uppercase.

notice that the end of definition there is no `;` 

## 1.5 Character Input and Output

Input is just some data that the user prompt to the program.

output is the data that the program returns. these are my definition i could be wrong though 🙂

so the get an input or output in C you could use the `stdio` library using `getchar and putchar` 

`getchar`  get a character form the user.

`putchar` print a character to the user

using this you can write a lot of fun programs like a file copying program 

where user write a charter and the program print it 

```c
// psudocode 
/*
read a character
	while (charater is not end-of-file indicator)
		output the character just read
		read a character
		Converting this into C gives:
*/
	
#include <stdio.h>
/* copy input to output; 1st version */
main()
{
	int c;
	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}

// or this 
int main() {
	int c;
	
	while ((c == getchar()) != EOF) {
		putchar(c);
	}
}
```

so here we prompt the user for a char then we check if it is equal to `EOF` but what is EOF?

`EOF` represent *End Of File* it is a constant in the `stdio.h` library and it has the value of `-1` .

char are represented as a numbers from 0 to 255 as 1 byte that's why we specified an `int` type for `c` , notice that `EOF`is not included this is why check to it .

if false user prompted with new value if false it's end of file .

### Exercise 1-6

Verify that the expression `getchar() != EOF is 0 or 1`

0: means true.

1: means false.

### Exercise 1-7

Write a program to print the value of EOF.

```c
#include <stdio.h>

int main(void) {
  printf("This is the value of EOF: %d\n", EOF); // value of EOF is -1
  return 0;
}
```

### 1.5.2 Character Counting

```c
#include <stdio.h>
/* count characters in input; 1st version */
main()
{
	long nc;
	nc = 0;
	
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc); // ld conversion means long
}
```

Here we count how many chars in the input .

The `++nc` is to increment the `nc` by one, the `++nc` and `nc++` both increment value by one but in a different way

To explain here is this code: 

```c
#include <stdio.h>
/* count characters in input; 1st version */
main()
{
	int c = 0;
	printf("%d", ++c) // --> This would increment value by one and print it 1
	printf("%d", c++) // --> This would print value and incremented so 1
	printf("%d", c)   // --> This is 2 
}
```

```c
#include <stdio.h>

int main(void)
{
  double nc;

  // i reallu don't know how this works and see not output.
  for (nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%0.f\n", nc);
}
```

This prints how many characters in the input.

### 1.5.3 Line Counting

This program counts input lines each time user make a new line we increment counter value.

```c
#include <stdio.h>

int main(void)
{
  int character;
  int line_counter = 0;
  while ((character = getchar()) != EOF)
  {
    if (character == '\n')
    {
      ++line_counter;
    }
  }
  printf("%d\n", line_counter); 
}
```

Inside the `while` loop we have an `if` statement either `true` or `false` .

if you notice we compare number to char but a char is represented in C as an ASCCI value so the value of `'A' = 65` so, the escape sequence like `'\n'` note this is just a character and it is represented as 10 in ASCCI 

### Exercise 1-8

Write a program to count blanks, tabs, and newlines.

```c
#include <stdio.h>

int main(void) {
  int counter = 0;
  int c;

  while ((c = getchar()) != EOF)
  {
    if (c == '\n' || c == '\t' || c == ' ') {
      ++counter;
    }
  }
  printf("%d\n", counter);
}
```

### Exercise 1-9

Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.

```c
#include <stdio.h>

int main(void)
{
  int character;
  int is_balnk = 0;

  while ((character = getchar()) != EOF)
  {

    if (character == ' ')
    {
      if (is_balnk == 0)
      {
        putchar(' ');
      }
      is_balnk = 1;
    }
    else
    {
      putchar(character);
      is_balnk = 0;
    }
  }

  return 0;
}
```

### Exercise 1-10

Write a program to copy its input to its output, replacing each tab by \t, each
backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
unambiguous way.

```c
#include <stdio.h>

int main(void)
{
  int character;
  int tab_counter = 0;
  int is_blank = 0;

  while ((character = getchar()) != EOF)
  {
    if (character == '\b')
    {
      putchar('\\');
      putchar('b');
    }
    if (character == '\\')
    {
      putchar('\\');
    }
    if (character == ' ')
    {
      is_blank = 1;
      ++tab_counter;
      if (tab_counter == 4)
      {
        putchar('\\');
        putchar('t');
        tab_counter = 0;
      }
    }
    else
    {
      for (int i = 0; i < tab_counter; i++)
      {
        putchar(' ');
      }
      tab_counter = 0;
      is_blank = 0;
    }
    if (is_blank == 0)
    {
      putchar(character);
    }
    is_blank = 0;
  }

  return 0;
}
```

This is not a good solution but it's 3:30 AM so freak it, it is what it is.

### 1.5.4 Word Counting

This Program count words, lines, and characters

```c
#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */
main()
{
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c = '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
```

`||` : This is the OR operator.

`&&` : This is the AND operator.

when if statement is satisfied else if wont be checked.

### Exercise 1-11

How would you test the word count program? What kinds of input are most
likely to uncover bugs if there are any?

1. There is a type on the second if statement when checking if c equals to ‘\t’

This is the only problem in the code 

### Exercise 1-12

Write a program that prints its input one word per line.

```c
#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{

	int c, state;
	state = OUT;
	while ((c = getchar()) != EOF)
	{
    if ((c == ' ' || c == '\n' || c == '\t')) {
			if (state == IN) {
				putchar('\n');
				state = OUT;
			}
		}
		else {
			putchar(c);
			state = IN;
		}
	}
}

```

## 1.6 Arrays

In this program we count the occurrence of each number and spaces "Blank, Tab, New Line”

```c
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
```

 `int ndigit[10];` This is an array declaration of type integer, in C we declare an array and give it's length.

using `for` we can traverse the array, using `[i]` to get an index of it in an each iteration.

### Exercise 1-13

Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

```c
#include <stdio.h>

#define MAX_LENGTH 10
#define IN 1
#define OUT 0

int main(void)
{
  int c, state, char_counter;
  int nword[MAX_LENGTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  state = OUT;
  char_counter = 0;

  while ((c = getchar()) != EOF)
  {
    if ((c == ' ' || c == '\n' || c == '\t'))
    {
      if (state == IN)
      {
        if (char_counter < MAX_LENGTH)
        {
          ++nword[char_counter - 1];
        }
        state = OUT;
        char_counter = 0;
      }
    }
    else
    {
      ++char_counter;
      state = IN;
    }
  }

  for (int i = 0; i < MAX_LENGTH; i++)
  {
    printf("%2d | ", i + 1);
    for (int j = 0; j < nword[i]; j++)
    {
      putchar('*');
    }
    putchar('\n');
  }
}

```

```c
	input: hello hello
	output: 
	 1 |
	 2 |
	 3 |
	 4 |
	 5 | **
	 6 |
	 7 |
	 8 |
	 9 |
	10 |
```

I asked AI if this solution is correct and it says yes so yes it is 🙂.

### Exercise 1-14

Write a program to print a histogram of the frequencies of different characters
in its input.

```c
#include <stdio.h>

#define OUT 0
#define IN 1
#define CHARS_NUMBER 127
#define IGNORED_CHARS 32

int main(void)
{
  int c, state;
  int nchars[CHARS_NUMBER];

  for (int i = 0; i < CHARS_NUMBER; i++)
  {
    nchars[i] = 0;
  }

  state = OUT;

  while ((c = getchar()) != EOF)
  {
    ++nchars[c - IGNORED_CHARS];
  }

  for (int i = 0; i < CHARS_NUMBER; i++)
  {
    if (nchars[i] > 0)
    {
      printf("%3c | ", i + IGNORED_CHARS);
      for (int j = 0; j < nchars[i]; j++)
      {
        putchar('#');
      }
      putchar('\n');
    }
  }
  return 0;
}
```

```c
input: Hello, world! This is a test input for the histogram program.
	output: 
	   | ##########
	!  | #
	,  | #
	.  | #
	H  | #
	T  | #
	a  | ###
	d  | #
	e  | ###
	f  | #
	g  | ##
	h  | ###
	i  | ####
	l  | ###
	m  | ##
	n  | #
	o  | #####
	p  | ##
	r  | #####
	s  | ####
	t  | #####
	u  | #
	w  | #
```

## 1.7 Functions

So far we have used several function `printf` `getchar` `puthcar` but, these functions ared defined in the *Standard input output library.*

let's make functions, since C has no exponentiation operator, let's make a function to power an integer `power(m, n)`;

```c
#include <stdio.h>

int power(int m, int n); // function declaration

int main(void)
{

  int i;
  for (i = 0; i < 10; ++i)
  {
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
  }
  return 0;
}

// int power(base, n)
// int base, n;
int power(int base, int n)
{
  int p;
  p = 1;
  for (int i = 1; i <= n; ++i)
  {
    p = p * base;
  }
  return p;
}
```

```c
return-type function-name(parameter declarations, if any)
{
	declarations
	statements
}
```

`int power(int base, int n)` : is a definition function 

### Exercise 1.15

Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */

#define STEP 20
#define UPPER 300

double fah_to_cels(int fahr);

int main(void)
{
  for (int i = 0; i < UPPER; i = i + STEP) {
    printf("%3d | %3.1f\n", i, fah_to_cels(i));
  }
}

double fah_to_cels(int fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}
```

The `fah_to_cels` : is a function produce `double` type and take an `int` type.

## 1.8 Arguments - Call by Value

This is the part that got me a lot of headache we first covering this topic, it’s the different between passing by value and passing by reference.

in C we pass by value to a function for primitive data types such `int double char...` but, for non primitive like Arrays we pass by reference "*Arrays memory address*” to a function, there is no array's copying.

also in C we can pass primitive data types by reference using a pointer more on that later.

## 1.9 Character Arrays

```c
#include <stdio.h>

#define MAXLENGTH 1000

int foo(char line[], int lim);
void copy(char to[], char from[]);

int main(void)
{

  int length;
  int max;
  char line[MAXLENGTH];
  char longest[MAXLENGTH];

  max = 0;
  while ((length = foo(line, MAXLENGTH)) > 0)
  {
    if (length > max)
    {
      max = length;
      copy(longest, line);
    }
    if (max > 0)
    {
      printf("%s", longest);
    }
  }

  return 0;
}

int foo(char s[], int lim)
{
  int i, c;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}
```

### Exercise 1-16

Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text

```c
#include <stdio.h>

#define MAXLENGTH 1000

int foo(char line[], int lim);
void copy(char to[], char from[]);

int main(void)
{
  
  int length;
  int max;
  char line[MAXLENGTH];
  char longest[MAXLENGTH];

  max = 0;
  while ((length = foo(line, MAXLENGTH)) > 0)
  {
    if (length > max)
    {
      max = length;
      copy(longest, line);
    }
    if (max > 0)
    {
      printf("%s...\n", longest);
    }
  }

  return 0;
}

int foo(char s[], int lim)
{
  int i, j, c;

  for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 1) {
      s[j] = c;
      j++;
    }
  }
  if (c == '\n')
  {
    s[j] = c;
    ++j;
  }
  s[j] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}
```

here i couldn't store all characters due to i still didn't learn about memory in C, so i only stored a string of `MAXLENGTH` and count all string chars.

### Exercise 1-17

Write a program to print all input lines that are longer than 80 characters

```c
/*
  Exercise 1-17. Write a program to print all input lines that are longer than 80 characters
  when user write an input  after they press new line '\n'
  get it and check if that line has more than 80 lines
  store it in the mu_string array
  and using for loop print it
 */
#include <stdio.h>

int get_user_line(char s[], int limit);

#define MINLENGTH 3
#define MAXLENGTH 10000

int main(void)
{
  char my_string[MAXLENGTH];
  int c;
  while (MINLENGTH < get_user_line(my_string, MAXLENGTH))
  {
    int i;
    i = 0;
    while (my_string[i] != '\0')
    {
      printf("%c", my_string[i]);
      ++i;
    }
  }
}

int get_user_line(char s[], int limit)
{
  int c, i, j;
  j = i = 0;
  while ((c = getchar()) != '\n')
  {
    if (i < limit - 2)
    {
      s[j] = c;
      ++j;
    }
    ++i;
  }
  s[j] = '\n';
  s[j + 1] = '\0';
  return i;
}
```

### Exercise 1-18

Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines

```c
/*
  Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines
 */
#include <stdio.h>

#define MAXLENGTH 300

int get_user_line(char s[], int limit);
void formate_line(char line[], char new_line[]);
void print_line(char line[]);

int main(void)
{
  char line[MAXLENGTH];
  while (get_user_line(line, MAXLENGTH) == 0)
  {
    char formated_line[MAXLENGTH];
    formate_line(line, formated_line);
    print_line(formated_line);
  }
  return 0;
}

int get_user_line(char s[], int limit)
{
  int c, i;
  for (i = 0; i < limit - 2 && (c = getchar()) != '\n'; ++i)
  {
    s[i] = c;
  }
  s[i] = '\n';
  s[i + 1] = '\0';
  return 0;
}

void formate_line(char line[], char new_line[])
{
  int i, j;
  i = j = 0;
  while (line[i] != '\0')
  {
    if (line[i] != ' ' && line[i] != '\t')
    {
      new_line[j] = line[i];
      ++j;
    }
    ++i;
  }
}

void print_line(char line[])
{
  int i;
  i = 0;
  while (line[i] != '\0')
  {
    printf("%c", line[i]);
    ++i;
  }
}
```

for the sake of not using pointers this took me over 1 day, there is only one bug here if second input is fewer then previous one it will look like this

```
first input: "HelloWorld"
second input: "1337"
The output of the second input would be like this
-> "1337\n\0orld" :) 
```

### Exercise 1-19

Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.

```c
#include <stdio.h>

int get_user_line(char s[], int limit);
void reverse_line(char s[], char reversed_line[], int limit);
void print_line(char line[]);
void new_string(char s[], int limit);

#define MAXLENGTH 300

int main(void)
{
  char s[MAXLENGTH];

  while (get_user_line(s, MAXLENGTH) == 0)
  {
    char reversed_line[MAXLENGTH];
    new_string(reversed_line, MAXLENGTH);
    
    reverse_line(s, reversed_line, MAXLENGTH);
    print_line(reversed_line);
  }
}

int get_user_line(char s[], int limit)
{
  new_string(s, limit);
  int c, i;
  i = 0;

  while (i < limit - 2 && (c = getchar()) != '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\n';
  s[i + 1] = '\0';

  return 0;
}

void reverse_line(char s[], char reversed_line[], int limit)
{

  int i, j;
  j = 0;

  for (i = limit - 2; i >= 0; i = i - 1)
  {
    if (s[i] >= '!' && s[i] <= '~')
    {
      reversed_line[j] = s[i];
      ++j;
    }
  }
  reversed_line[j] = '\n';
  reversed_line[j + 1] = '\0';
}

void print_line(char line[])
{
  int i;
  i = 0;
  while (line[i] != '\0')
  {
    printf("%c", line[i]);
    ++i;
  }

}

void new_string(char s[], int limit) {
  for (int i = 0; i < limit; i++)
  {
    s[i] = ' ';
  }
}
```

the `new_string` function just assign spaces to all array indexes.

## 1.10 External Variables and Scope

variables that we declare inside functions are local known as *automatic variables*, it means that we can access them in other functions unless we pass them as a parameters.

so as an alternative to *automatic variables* it's possible to define variable to be external *global variables* 

external variable must be defined once in outside of any function.

to use an external variable in the function you need to use the `extern` word for example

```c
int foo;

int main(void) {
	extern int foo;
}
```

`extern` word in this example cause storage to be allocated for the variable `foo`  in the `main`  function.

when it comes to pest practice we can ignore the `extern` word also this kind of global variables we store them in a header.

a header file like `stdio.h`  has declaration of global variables and functions, that we include using the `#include` 

**You should note that we are using the words definition and declaration carefully here is why:** 

- Declaration introduces the name and type of a variable, function, but it doesn't allocate memory or initialize value of variable.

```c
int foo(int baz, int bar);
```

- Definition not only declares the name and type of a variable or function but also allocates memory for variables and initializes them

```c
int x = 5;

int add(int a, int b) {
    return a + b;
}

```

**At this point we have covered what might be called the conventional core of C. With this handful of building blocks, it's possible to write useful programs of considerable size, and it would probably be a good idea if you paused long enough to do so. These exercises suggest programs of somewhat greater complexity than the ones earlier in this chapter** 💜.

```c
#include <stdio.h>

#define MAXLENGTH 400

// Global varibales
int ntabs = 3;

int get_user_line(char s[], int limit);
void remove_line_tabs(char s[], char fomrated_line[]);
void print_line(char formated_line[]);

int main(void)
{
  char s[MAXLENGTH];
  while (get_user_line(s, MAXLENGTH) == 0)
  {
    char formated_line[MAXLENGTH];
    remove_line_tabs(s, formated_line);
    print_line(formated_line);
  }
}

int get_user_line(char s[], int limit)
{
  int c, i;
  i = 0;

  while (i < limit - 1 && (c = getchar()) != '\n')
  {
    if (c == EOF)
      return -1;

    s[i] = c;
    ++i;
  }
  s[i] = '\n';

  return 0;
}

void remove_line_tabs(char line[], char new_line[])
{
  int i, j, space_counter, tabs_counter;
  i = j = space_counter = tabs_counter = 0;

  while (line[i] != '\n')
  {
    if (tabs_counter <= ntabs)
    {
      // if current line is space 
      if (line[i] == ' ')
      {
        new_line[j] = ' ';
        ++space_counter;
        ++j;
      }
      else if (line[i] == '\t')
      {
        if (space_counter > 0)
        {
          int tab_index = j;
          while (j < tab_index + space_counter)
          {
            new_line[j] = ' ';
            ++j;
          }
        }
        // no space count 
        else
        {
          new_line[j] = '\0';
          ++j;
        }
        space_counter = 0;
        ++tabs_counter;
      }
      // if current line is char and not a tab nor a space 
      else
      {
        new_line[j] = line[i];
        ++j;
      }
    }
    else
    {
      new_line[j] = line[i];
      ++j;
    }
    ++i;
  }
  new_line[j] = '\n';
}

void print_line(char line[])
{
  int i;

  for (i = 0; line[i] != '\n'; ++i)
  {
    printf("%c", line[i]);
  }
  printf("%c", '\n');
}

```

i start learning `lldb`  debugger it's nice and easy to use, batter than vs shity debugger.

### Exercise 1-21

Write a program `entab` that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for `detab`.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?

```c
/*
  Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
  number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
  When either a tab or a single blank would suffice to reach a tab stop, which should be given
  preference?
 */
#include <stdio.h>
#include "../tab_header/tab.h"

void remove_line_blanck(char s[], char formated_line[]);

int nspaces = 3;

int main(void)
{
  char s[MAXLENGTH];
  while (get_user_line(s, MAXLENGTH) == 0)
  {
    char formated_line[MAXLENGTH];
    remove_line_blanck(s, formated_line);
    print_line(formated_line);
  }
  return 0;
}

void remove_line_blanck(char line[], char new_line[])
{
  int current_index, new_line_index, tabs_counter, space_counter;
  current_index = new_line_index = tabs_counter = space_counter = 0;

  while (line[current_index] != '\n')
  {
    if (space_counter <= nspaces)
    {
      if (line[current_index] == '\t')
      {
        new_line[new_line_index] = line[current_index];
        ++new_line_index;
        ++tabs_counter;
      }
      else if (line[current_index] == ' ' && tabs_counter > 0)
      {
        int space_index = new_line_index;
        while (new_line_index < space_index + tabs_counter)
        {
          new_line[new_line_index] = '\t';
          ++new_line_index;
        }
        space_counter =  tabs_counter = 0;
      }
      else
      {
        new_line[new_line_index] = line[current_index];
        ++new_line_index;
      }
    }
    else
    {
      new_line[new_line_index] = line[current_index];
      ++new_line_index;
    }
    ++current_index;
  }
  new_line[new_line_index] = '\n';
}

```

if these are wrong i'm not gonna repeat them this was my approach.

count number of tabs, when hitting a space replace it by number of tabs passed * a tab.

### Exercise 1-22

Write a program to '’fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the `n-th` column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

```c
#include <stdio.h>
#include "../header/tab.h"

void formate_line(char line[], char new_line[]);

int ncolumn = 14;

int main(void)
{
  char s[MAXLENGTH];

  while (get_user_line(s, MAXLENGTH) == 0)
  {
    char formated_line[MAXLENGTH];
    formate_line(s, formated_line);
    print_line(formated_line);
  }
}

void formate_line(char line[], char new_line[])
{
  int i, last_space, no_space_flag;

  last_space = -1; // -1 means no space before
  i = no_space_flag = 0;

  while (line[i] != '\n')
  {
    if (i % ncolumn == 0 && i != 0)
    {
      if (line[i] == ' ')
      {
        new_line[i] = '\n';
      }
      else
      {
        if (last_space != -1)
        {
          new_line[last_space] = '\n';
        }
        else
        {
          no_space_flag = -1;
        }
        new_line[i] = line[i];
      }
    }
    else
    {
      if (line[i] == ' ')
      {
        if (no_space_flag == -1) 
        {
          new_line[i] = '\n';
          no_space_flag = 0;
        }
        else {
          new_line[i] = line[i];
        }
        last_space = i;
      }
      else {
        new_line[i] = line[i];
      }
    }
    ++i;
  }
  new_line[i] = '\n';
  new_line[i + 1] = '\0';
}
```

```c
input: Deoxyribonucleicacid is DNA
output: Deoxyribonucleicacid
is DNA
```

There is a bug here can't say it though

/

### Exercise 1-23

Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nes

```c
// this is by far the hardest
#include <stdio.h>
#include "../header/tab.h"

int get_file_input(char s[], int limit);
void remove_comments(char line[], char new_line[]);
int main(void)
{
  //  get file input of size MAXLENGHT
  char s[MAXLENGTH];
  get_file_input(s, MAXLENGTH);

  // remove comments
  char formated_input[MAXLENGTH];
  remove_comments(s, formated_input);

  // print new file input witout any comment
  print_line(formated_input);
  return 0;
}

void remove_comments(char line[], char new_line[])
{
  int i, is_single_comment, is_multiple_comment, new_line_index;
  is_single_comment = is_multiple_comment = -1;

  for (i = new_line_index = 0; line[i] != '\0'; ++i)
  {
    if (is_single_comment == -1 && is_multiple_comment == -1) {
      // if single line comment
      if (line[i] == '/' && line[i + 1] == '/') {
        is_single_comment = i;
      }
      // if mulitple line comment detected
      else if (line[i] == '/' && line[i + 1] == '*') {
        is_multiple_comment = i;
      }
      else {
        new_line[new_line_index] = line[i];
        ++new_line_index;
      }
    }
    else {
    // if end of mulitple line comment
      if (line[i - 1] == '*' && line[i] == '/')
      {
        is_multiple_comment = -1;
      }
      else if (line[i] == '\n' || line[i] == '\0')  {
        is_single_comment = -1;
      }
    }
  }
}

int get_file_input(char s[], int limit)
{
  int c, i;
  i = 0;
  while ((c = getchar()) != EOF)
  {
    if (i > limit - 1)
    {
      printf("File Max lenght is: %d", limit);
      return -1;
    }
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return 0;
}

```