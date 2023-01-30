[Back](./readme.md)
# Week 2
###### 2023-01-24

## Arrays
Arrays are stored in continuous memory, with **no** bounds checking.

```c
char array[5] = {'A','B','C','D','E'};
int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int anArray[10]; /* Contents are undefined */
int a2[2][3] = { {1,2,3} , {4,5,6} };
```

`int anArray[10];` reserves 10 x `sizof(int)` = 10 x 4 bytes = 40 bytes for `anArray`.

## Strings
are just character arrays.

```c
char charArray[12];
char array2[5] = {'A','B','C','D','E'};
char name[21] = "ECM2433";
char lastArray[] = "Hello World!";
```

Note. a character uses single quotes, while a string uses double quotes.

`charArray` is uninitialised so contains random stuff.

`lastArray: H, e, l, l, o,  , W, o, r, l, d, !, \0,`

the **null** character. All strings in C are "null terminanted", 1 byte of memory.

Without the null character the string will keep running.

### Printing

```c
printf("%*.*s\n", wid, prec, str);
printf("%20.10s\n", "Hello world!");
```

Width is how many characters the string will be formatted with. Precision is how many characters of the string will be shown.

```
character meaning
\n line-feed (new line)
\t horizontal tab
\v vertical tab
\b backspace
\r carriage return
\f form-feed (new page)
\\ backslash
\' single quote
\" double quote
%% percent sign
```

```c
#include <string.h>
char strA[] = "Test String";
char strB[] = "Test String 2";

strlen(strA);
// returns number of chars not including null terminator

strcpy(strA, strB);
// copies the string in strB into strA including null terminator

strcat(strA, strB);
// concatenates strB onto the end of strA, overwritting strA from the first null terminator

strcmp(strA, strB);
// returns 0 if the two strings are the same, otherwise some other int value

sprintf(buffer, "%s %d", strA, i);
// like printf, but places the result in buffer instead of printing out.

```
## Pseudo random numbers

### Random number distributions
- Uniform
- Normal
- Poisson
- Bernoulli
- Gamma

```c
#include <stdio.h>
#include <stdlib.h> // needed for rand() function

int main ()
{
    int n;
    for (n = 0; n < 10; n++)
        printf("%d\n", rand());
    return 0;
}
```

This code will produce the same 10 pseudo random numbers each time. The next random number depends on the last, and will eventually loop back to the begining.

**Simple algorithm**
$$$
    j := (j \times\ a\ +\ c)\ \%\ m
$$$

This algorithm is a (terrible) way to generate pseudo random numbers.

```c
int i;
printf("some random numbers between 0 and 10? \n");
for (i=1;i<=10;i++)
    printf(" number %02d: %f\n",i,10*rand()/RAND_MAX);
    // this will return 0 because of integer division
printf("some random numbers between 0 and 10:\n");
for (i=1;i<=10;i++)
printf(" number %02d: %f\n",i,10.0*(float)rand()/RAND_MAX);
// Here we cast an integer to a float
printf("some random integers between 1 and 10:\n");
for (i=1;i<=10;i++)
printf(" number %02d: %d\n",i,1+rand()%10);
```

**Integer division in C rounds down**

If any of the numbers is a float, then the arithmetic result is a float.

Mathematical expressions are evaluated from left to right as long as there are no brackets, and the operators have the same precedence (exponentation, add and subtract, multiply and divide).

```c
#include <stdio.h>
int main ()
{
    char c = 'a';
    int n = 10*c; /* c promoted to int before multiplication */
    float f = c/12.0; /* c promoted to float before division */
    printf("%c %d n = %d f = %f\n", c, c, n, f);
    return 0;
}
// a 97 n = 970 f = 8.083333
```

To seed `rand()` use `srand()` where the input is the random seed.

`rand()` does not produce very good random numbers and should not be used for proper statistical modelling. It is okay to use for a bit of randomness.

For proper (pseudo) random numbers we will use the GNU Scientific Library (GSL).

## Functions

In C a function is a uniquely named group of program statements (no overloading) which accepts zero or more arguments or parameters, returns zero or one value to the calling code.

Curly brackets `{}` define the **scope** of the function.

Every program must have a main function of the form:
```c
int main()
{
    // zero or more statements
    return 0;
}
```

1. The compiler needs to know a function's definition before it is called
2. Functions may appear in any order in the program, with the main function first by strong convention.
3. The functions may call each other, so there is no order of the function definitions.
4. The code for the function may not be in the same program.

Procedures are functions with no return value.

### Function Prototypes

```c
void printArray(char []);
int anIntFunction();
```

## Scope

Variables only exist while they are in scope.

Variables can be global, but it is generally **very** bad practice.

## Static

Declared using the `static` keyword.

```c
static int pageNum = 0;
```

These are initialised once when the function is first called and retain their value when they go out of scope.
