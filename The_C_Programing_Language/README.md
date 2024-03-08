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

In the top of our code there is the `#include <stdio.h>` a header that tells the compiler to include information about the `Standard input/output library` where the `printf` function is defined and implemented.

Functions communicate and share data with each other using _arguments_ inside `()`_,_ in our `main` implementation we didn't provide any arguments to it.

A function can be called by using it's name and parentheses `printf()` , this function takes a lot of arguments but in out example it takes just the string **"Hello, World!”.**

The `\n` is a C notation of new line, it's _escape sequence character,_ we will know more about those later, so `\n` informs `printf` to print a new line to understand it more we can implement the same Hello, World! program like this ways

```c
#include <stdio.h>

int main() {
	printf("hello, ");  // no new line
	printf("world!");    // no new line
	printf("\n");       // new line here
}
```

```c
#include <stdio.h>

int main() {
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

This program give a compilation Warning for an unknown escape character `\c`.

## 1.2 Variables and Arithmetic Expressions

In the next program we will use the formula `oC=(5/9)(oF-32)` to print Fahrenheit
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
- we have the `/**/` this sign is a comment when using it the compiler ignores whatever is written inside it, in this example it describes the purpose of the function
- `int fahr, celsius;` and `int lower, upper, step;` these are declaration statement in C all variables must be declared before they are used, usually at the beginning of the function
  - here the `int` means that variables value must be of type Integer, this is important and here is why, when compiling the code by the compiler we need to specify what is the type of the variable to know how much memory the compiler should assign to it or allocate to it i don't know wish term should i use here
  - C provides several data types beside `int` here are some of them
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

<div style="text-align: center">

| %d    | print as decimal integer                                                                |
| ----- | --------------------------------------------------------------------------------------- |
| %6d   | print as decimal integer, at least 6 characters wide                                    |
| %f    | print as a floating point number                                                        |
| %6f   | print as a floating point number, at least 6 characters width                           |
| %.2f  | print as a floating point number with 2 characters after decimal                        |
| %6.2f | print as a floating point number with 2 characters after decimal, at least 6 chars with |
| %o    | print as octal                                                                          |
| %x    | print as hex                                                                            |
| %c    | print as char                                                                           |
| %c    | print as string                                                                         |
| %%    | print the symbol %                                                                      |

</div>


There are more than these precisions.
