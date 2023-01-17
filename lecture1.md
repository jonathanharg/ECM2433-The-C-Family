[Back](./readme.md)
# Introduction
**Lecture 1 - 2023-01-17**

## Why learn C
- Lot of existing C code
- Other languages have similar syntax
- C is perfect for operating systems and embedded systems
- Fast to execute, close to assembler speeds
- C has a very low runtime overhead
- Very small runtime, small memory footprint

**C is:**
- imperative: describes computation in terms of statements that change a programs state
- procedural/functional
- compiled
- statically typed: types are check before runtime
- weakly typed: supports implicit type conversions
- available on almost every platform, portable
- very fast
- explicitly memory managed
- ANSI/ISO standardised

**C does not have:**
- runtime error checking (bounds, initial values, etc.)
- sophisticated exception handling

```c
/* Hello world Program */       // Comment
#include <stdio.h>              // compiler directive

int main()                      // main function
{                               // start block/scope
    printf("Hello world!\n");   // output some text
    return 0;                   // finishe with success
}                               // end block/scope
```

diagram slide 16

# GNU: GNU's not Unix
Free, UNIX-compoatible operating system launched by Richard Stallman in 1983.

GNU system conttains all of the official GNU software packages, including **gcc**, the **GNU** **C**ompiler **C**ollection

> `gcc myProgram.c`

Compiles C program *myProgram.c* and links it to create executable *a.out*.

> `./a.out`

To run the program.

Standard compile:
> `gcc -ansi -c myProgram.c -o myProgram.o`

and link
> `gcc myProgram.o -o myProgram`
