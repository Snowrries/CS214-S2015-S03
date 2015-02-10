CS214 S03 -- Recitation 02
===============
## PA1 - Tokenizer
* Due date extended to 5:00pm on February 11th.
* Some clarifications will be posted to Sakai w/ some example test cases.
* Detailed assignment submission will be posted to Sakai

## More recommended reading
http://www.gnu.org/software/libc/manual/html_node/index.html


## A quiz of sorts...

* **What's the size of an int?**
    * Depends on the compiler but it must be at least 16-bits.
* **Can I use `pthread_create()`, a function in the POSIX standard library, on Mac OS X?**
    * Yes, OS X is POSIX (theoretically) compliant. 
* **Are the functions in BSD libc available in Linux?**
    * They might be but they don't have to be.
* **Why might your code behave differently on OS X vs. Linux?**
    * Different libc implementations
    * Different compilers
    * Different versions of **the same compiler**
* **What are the range of acceptable values for signed ints and unsigned ints on the *iLab machines*? (answers in powers of 2 are acceptable)**
    * signed ints range from -2^31-1 to 2^31-1
    * unsigned ints range from 0 - 2^32-1
    * Recall that even though x86_64 uses 64 bit words, the size of an int is left to the compiler. In this case, the gcc developers elected for 4 byte ints. 
* **I'm porting `gcc` to an architecture that has an 8-bit word size. As the `int` type is commonly used to represent the machine's word size, can I use it that way in my compiler?**
    * Sure, but that wouldn't be an ISO compliant C compiler.

## A brief Comp Org Review
* Everything is represented using bits
* Basic types really only speak to the size (number of bits) encoding of a type (signed, vs. unsigned)
* Pointers are references to memory.
* Complex types are simply arrangements of basic types
* What you see isn't necessarily what the computer has in memory (endianness)
* When you cast an object to another in Java, a bunch of secret magic stuff happens.
    * *Ok that's not actually true, you can see what happens [here](http://docs.oracle.com/javase/specs/jls/se8/html/jls-5.html#jls-5.5).

## Other Topics

### Makefiles
* Make is a fairly powerful build system that Dr. Russell will introduce in lecture.
* For now you can build examples by entering the recitation directory and using the shell command `make all`

### Preprocessor Macros
* We'll go into the gory details later in the semester but for now I'll say this. When you "compile" your code, you're actually doing a series of different things.
* Preprocessing is the first step in the compilation process.
* In short, the preprocessor is a simple text replacement tool. Simple in the sense that it's **very important** you understand it simply does text replacement. 
* The preprocessor takes various directives (the lines that begin with `#`) and performs text replacement
    * The `#include`, quite literally, takes the source code from the specified file and injects it into your code. 
    * The `-E` flag will stop gcc after preprocessing. Write a simple miniature program (that includes stdio.h), add the `-E` flag to gcc when compiling, and then take a look at the output file.
    
## Miniature Programs
* `ipaddr.c` - C Unions in action
* `clevercasting.c` - A demonstration of the power (and freedom) afforded to you by pointers
    * If you can follow the pointer arithmetic going on in here you should be golden
    * Note I've introduced a couple things including the `stdint.h` header and Preprocessor Macros.
