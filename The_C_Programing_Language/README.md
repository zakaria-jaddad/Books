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
