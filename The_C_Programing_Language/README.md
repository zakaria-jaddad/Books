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