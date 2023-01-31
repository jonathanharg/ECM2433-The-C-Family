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


