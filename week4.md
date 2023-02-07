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
