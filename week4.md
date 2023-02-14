[Back](./readme.md)
# Week 4
###### 2023-02-07

## Passing by Value

When passing by value a copy is made.

## Pass by reference

To manipulate the value of a parameter within a function it must be passed as a pointer.

The value of the thing passed in cannot be changed.

## Function Parameters

Parameters to functions are always passed by value.

To update the value of a parameter and pass the new value back to the calling function you must use pointers.

Since C functions can only return one value, this mechanism can be used to return other values to the caller.

## Passing arguments to the main function

```c int main ( int argc, char** argv )
```

Where `argc` is the number of arguments passed, and `argv` is the array of *string* values.

Technically the variable names can be anything, but they are **almost always** (by very strong convention), `argc` and `argv`.


## Pointers to functions

```c
int Plus (int a, int b) { return a + b; }
int Minus (int a, int b) { return a - b; }
int Multiply (int a, int b) { return a * b; }
int Divide (int a, int b) { return a / b; }


int doFunction (int a, int b, int (*myFunc)(int,int) )
{ return myFunc(a, b); }
```

Note. the brackets around `*myFunc` are needed. As `int *myFunc(int, int)` would definie a function that returns a pointer to an integer.

For example the `qsort` function in `stdlib.h` uses function pointers, by passing a comparison function that compares two elements of an array.

```c
void qsort ( void *myData, int numElements, int sizeOfElement, int (*comparisonFunction)(void *, void *) );
```

In use:
```c
int CompareFunction(*v1 , void *v2 )
{
    int *i1 = (int *)v1; remember that you need to cast void pointers
        int *i2 = (int *)v2;
    return *i1 - *i2;
}

int myList[] = {4 ,6 ,8 ,3 ,2 ,1 ,5 ,9 ,0};
int len = sizeof(myList)/sizeof(int); /* Number of elements in myList */
qsort(myList,len, sizeof(int), &CompareFunction);
```

## Structures

A variable that groups multiple items togheter, closest thing to a class.

```c
struct structName
{
    char varA;
    int varB;
}
```


```c
struct bookStruct
{
    char title[181] = "";
    char author[51] = "";
    float price;
    int numPages;
};

int main ()
{
    struct bookStruct myBook;
    struct bookStruct anotherBook;

    myBook.price = 12.99;
    strcpy(myBook.title,"The Joy of Programming in C");
    anotherBook = myBook;
    return 0;
}
```

## typedef

You can define your own datatypes using the `typedef` command:

```c
typedef struct bookStruct BOOK;
```

then we can use

```
BOOK myBook;
```

which is the same as

```c
struct bookStruct myBook;
```

Structures are often used in association with a pointer.

```c
BOOK *secondBook; /* a pointer */
if ( ( secondBook = (BOOK *)malloc(sizeof(BOOK)) ) == NULL )
{ /* error: not enough memory */ }
strcpy(secondBook->title, "Hidden Figures");
strcpy(secondBook->author, "Margot Lee Shetterly");
secondBook->price = 8.99;
secondBook->numPages = 384;
```

`secondBook->price` is shorthand for `(*secondBook).price`.

### Example: Linked List

```c
struct anode
{
    /* some data variables here, e.g.: */
    char data;
    struct anode *nextNode; // Note: a pointer to anode, not anode!
};
typedef struct anode NODE;

NODE *root = NULL;
```

```c
NODE *newNode;
if ( !(newNode = (NODE *)malloc(sizeof(NODE)))) { /* error */ }

newNode->data = 'A';
ndeNode->nextNode = NULL;

root = newNode;
```

## Input and Output

`scanf()` is like the reverse `printf()`

```c
#include <stdio.h>
int main()
{
    int k;
    do {
	printf("Please enter an integer: ");
	if (scanf("%d", &k) != 1)
	    break;
	printf("Read %d\n", k);
    } while (1);
    return 0;
}
```

### Stream

A stream is an abstraction of a file that provides a consisten interface to the programmer, regardless of the actual device.

A stream is buffered, so that data is not necessarily written to the device when the write command is issued. You can force the write to happen by flushing a stream.

May be text or binary. Needs to include `stdio.h`

### Errors

Errors from when system calls fail is comunicated through `errno`, a global variable.

```c
#include <errno.h>

int main (...)
{
    printf("Unable to read file %s: %d: %s\n", argv[1], errno, strerror(errno));
}
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main ()
{
    int *p = NULL;
    if (!(p = (int *)malloc(100000000000000*sizeof(int) ))) {
        printf("Malloc failed. %d: %s\n", errno, strerror(errno));
        return -1;
    }
    /* Do something with p */
    return 0;
}
```

`Malloc failed. 12: Cannot allocate memory`

A call to `ferror(fp)`
- determines whether the most recent operation on the file pointed to by fp produced an error
- returns 1 if an error occurred; 0 if not
- value is reset by each file operation

### Write to a Stream
- `fputc(ch, fp)`
- `fputs(str, fp)`
- `fprintf(fp, "character %c, integer %03d", ch, i)`

### Write to a Stream
- `char ch = fgetc(fp)`
- `fgets(str,count,fp)`
- `fscanf(fp, "%d,%d", &x, &y)`

### Other common stream functions
- `fflush(fp)`
- `remove("myFile.txt")`
- `rewind(fp)`

### Standard streams
- `stdin` input from the termin
- `stdout` output to the terminal; normal program output
- `stderr` output to the terminal; error and warning messages

`scanf` reads input from `stdin`; equivalent to `fscanf(stdin,...)`

`printf` sends output to `stdout`; equivalent to `fprintf(stdout,...)`
