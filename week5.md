# The C Preprocessor
###### Week 5 - 2023-02-17
## Preprocessor directives
```c
#include <stdio.h>
```

Here, the preprocessor finds the file `stdio.h` and replaces the include with the contents of the file.

`.h` files are called header files.

## \#include: <> vs ""

```c
#include <stdtio.h>
#include "myFile.h"
```

- `<stdio.h>` search for files using the path the pre-processor expect these files (in UNIX `/usr/include`)
- `"myFile.H"` search for the first *first* in the same directory, *then* fall back to the "standard" files.

## \#define

```c
#define TRUE 1
#define FALSE 0
```

We can defina a macro and replace any instances of the macro name with its definition.

> Note, it does not replace in quoted strings e.g `printf("It is FALSE")` prints `It is FALSE`

We can also create functions

```c
#define ADD(x,y) x+y

Z = ADD(12,n)
// Equates to
Z = 12 + n
```

Careful! Definitions are substitued before the compiler compiles the source doe, so related errors can be hard to trace.

## Selective Compilation

- `#ifdef` - if a symbol is defined
- `#ifndef` - if a symbol is not defined
- `#undef` - undefine a macro or symbol
- `#else` - otherwise
- `#elif` - else if
- `#endif` - end of the block

```c
#ifndef __UNIX__
/* some C code in here for UNIX systems*/
#else
/* some different C code in here for non-UNIX systems */
#endif
```

- `__FILE__` - the current file name
- `__LINE__` - the current line number in this file
- `__DATE__` - the date this object code was generated from the source
- `__TIME__` - the time this object code was generated from the source
- `__STDC__` - 1 if  this implementation of C conforms to the ANSI/ISO standard; any other value means not.

**Informal Rule** macros should have all capital names, to communicate to the reader this is a macro. System macros start with two underscores, so that they don't interfere with your own macros and so they are recognisable.

## Program structure

All of the
- `#include`s
- `struct`s
- function prototypes

can be moved into a single header file ending in `.h`

The header file is **always** named after the code file it blongs to.
