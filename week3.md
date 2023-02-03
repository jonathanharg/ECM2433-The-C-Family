[Back](./readme.md)
# Week 3
###### 2023-01-31

## Pointers
```c
char ch = 'A'; // variable is a character
char *p; // variable p is a pointer to a character
char* p; // equivilent

p = &ch // p is a pointer to ch
```

## * and &
if `x` is any datatype, then `&x` is the location in memory (its "address") where `x` is currently stored.


if `x` is a pointer then `<datatype> *x` declares `x` to contain the memory address of a variable of type `<datatype>`.

However `*x` says to go to the memory address stored in `x` and bring back the value (of type `<datatype>`) stored there.


## Size of a pointer
The amount of memory used to store a pointer depends on the computer, OS, and compiler. Normally

Windows 32-bit: 32 bits = 4 bytes
Windows 64-bit: 64 bits = 8 bytes

## Pointer Arithmetic
A memory address is just an integer.

```c
x++; // will increase x by the size of the type x points to.
```

## Void Pointers
```c
void *p;
```

Here `p` is a generic pointer type. We then have to cast this pointer to use it.

```c
char c = 'A';
float n = 10.0;
void *p;

p = &c;
printf("p point to %c\n", *(char *)p);

p = &n;
printf("p points to %f\n", *(float *)p);
```

## Runtime errors using pointers
- Memory fault
- Segmentation fault

Caused by
- Trying to access memory to which it is not allowed access
- Trying to access memory in a way that is no allowed (e.g. trying to overwrite the OS)

It is possible to corrupt your own program with memory and pointer errors.

> Premature optimisations with pointers can be an easy mistake to make.

## Dynamic memory allocation
**Allocating an array whose size is decided at runtime.**
```c
#include <string.h>
#include <limits.h>

int main ()
{
    unsigned int n = UINT_MAX;
    char ch[n];
    strcpy(ch, "Elephant")
    return 0;
}
```

`Memory fault(coredump)`

Error probably caused by the fact that there is not enough free, contiguous memory to allocate to the array.

1. **Declare an array whose size is decided at runtime** No way of knowing how much free contiguous memory is available. You may not know how much is required before declaring the array.
2. **Process the data in smaller chuncks** Possible, but still requires a lot of extra programming.
3. **Dynamically allocate memory at runtime using pointers.** Here we can check whether memory allocation was successful.

```c
#include <stdlib.h>

int* p = NULL;
p = (int *)malloc(23); // Gives 23 bytes
p = (int *)malloc(23*sizeof(int)); // Gives 23 integers worth of memory
```

**There might not be enough memory!!**

```c
p = (int *)malloc(100000000000000000000*sizeof(int)); // not enough memory
printf("p = %p\n", p); // p = nil
```

You must **always** trap the fact that memory was not allocated:

```c
if (!(p = (int *)malloc(1000000000000000000*sizeof(int))))
{
    printf("Out of memory\n");
    exit(1);
}
```

## Variables and scope

"Normal" variables
```c
void myFunction ()
{
    int p = 10000;
} // p goes out of scope at the end of the function and its allocated memory is released.
```

Dynamically allocated variables
```c
void myFunction ()
{
    int* p = (int *)malloc(100000000);
} // MEMORY LEAK: allocated memory is NOT released, even though p goes out of scope
```

Here we have a **memory leak**, the 8 bytes (on a 64-bit system) occupied by `p` are released, but the 100000000 bytes reserved for `p`, and to which `p` points to, are not.

## Freeing Memory
Whenever you use malloc you much **ALWAYS** explicitly free the memory before the variable goes out of scope

```c
void myProcedue()
{
    int *p = (int *)malloc(100000000);
    free(p);
}
```
