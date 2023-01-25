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
$$
    j := (j \times\ a\ +\ c)\ \%\ m
$$

This algorithm is a (terrible) way to generate pseudo random numbers.


