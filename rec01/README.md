CS214 S03 -- Recitation 01
===============

## Recitation Format
1. Questions from students
* Questions for students
* Theory stuff
* Miniature programs

### About Recitation in General
* I don't come to recitations with the intention of rehashing material covered in lecture. This means that **if you have a question or you're uncertain about something Dr. Russell talked about please ask.**

* Recitation attendance is totally optional.

* You can attend whichever recitation section you prefer.

* My goal in recitation is to extend the material talked about in lecture and to get you guys thinking critically.

* I tend to focus on the theory of the language and then how it plays into real-world programming.


* I'm here to help but if you don't tell me you need help I can't!

## Recommended Reading
*In no particular order*

* POSIX man pages (available on any iLab machine)
* Kernighan & Ritchie -- The C Programming Language 2nd Edition
* C11 Final Draft Specification (N1570)

## Recommended Practices
* Read the API (man pages).
* Write miniature programs.
* Ask questions.
* Assumptions are dangerous; don't make them.
* Think (at least) twice, code once.

* Take care to understand the distinctions between the language (C), the libraries (libc), and compilers.

## Language Stuff

### The Basics

* C is a programming language standardized by the ISO (a standards body).
* There are different "standards" or revisions of the C programming language (eg. ANSI C, C99, & C11).
    * Each revision to the language adds features and modifies conventions.
* For all intents and purposes we are using **C99** in this course (mostly because ANSI C is painful and the iLabs don't support C11)



### Basic Data Types
*Note -- this is is not exhaustive*

#### Signed Integer Types
* signed char 
* short (ie. short int)
* int
* long (ie. long int)* long long (ie. long long int)#### Unsigned Integer Types
* unsigned char* unsigned short* unsigned long* unsigned long long#### Floating Point Types
* float* double* long double#### Chars* char* signed char* unsigned char
#### Comments on Basic Types
* When you start writing C (especially when coming from Java), it's easy to think in absolutes (eg. an int IS 32-bits). This is dangerous thinking.
* A lot of things are platform dependent in C and you should be cognizant of that as you write. 
* The C specification dictates **relative sizes** and **minimum sizes** for various data types.
* Specific info about datatype sizes on a machine can be found in the `limits.h` file (or the requisite man page).
### Derived Types

#### Arrays
* A contiguously allocated nonempty set of objects with a particular member (element) type.

#### Structures (struct)
* A **sequentially allocated** nonempty set of member objects, each of which has an *optionally specified* name and type.

#### Enumerations (enum)
* A set of named constants that map to integer values.

#### Unions
* "An **overlapping** nonempty set of member objects, each of which has an optionally specified name and possibly distinct type."
* **A machine independent way of manipulating a different "types" of data that share a single storage space**

#### Functions
* Functions are a type in C; specifically a function type consists of the return type of a function as well as it's parameters.
* This will be important later.

#### Pointers
* "Describes a type whose value provides a reference to an entity of a referenced type."
* **The value of a pointer is simply a reference to something stored somewhere else**

### Example Claims:
* The following claims are absolutely true as dictated by the ISO C Specification.

* An `int` must be *at least* 16-bits large and a `short ≤ int ≤ long`.
* *Typically* an int is used to represent the *word* size on a machine however it doesn't have to.
* A `char` is number of bits for smallest object that is not a bit-field (byte).
    * Put another way, a char is a byte.
    * Fun fact for pedants: a byte doesn't *have* to be 8-bits and on some systems it isn't.
    * The `CHAR_BIT` macro is but for all practical purposes convention says it is.
* A `float` is a single precision floating-point number.
* A `double` is a double precision number.
* An `unsigned char` is the same size is a char but guaranteed to be unsigned.


### Operators & Precedence
* Making tables in markdown is painful. See [here](http://en.cppreference.com/w/c/language/operator_precedence) instead.


## C Standard Libraries
* **libc**, The C Standard library consists of a set of interfaces (APIs). There are numerous **implementations** of these interfaces.
* The ISO C Standard Library consists of the APIs specified in the ISO C specification (like n1570)
    * Recall that with each revision of the C specification we add new things (eg. flexible-array members in C99 or threads.h in C11)
    
### A Practical Example
* The **GNU C Library** or **glibc** is the GNU implementation of the C Standard library.
This is the implementation used on Linux.
* In addition to implementing the ISO libc API, 
it provides an implementation of the C POSIX Library as well as APIs unique to glibc.
* While glibc is used on Linux **it is not used on other common Unices (eg. Mac OS X, Solaris, FreeBSD)**.
* Below are some examples of APIs implemented in glibc. The categorization of a function/header speaks to its portability.



#### ISO C Standard Library

##### Headers
* assert.h
* ctype.h
* stdio.h
* stdlib.h
* string.h
* time.h

##### Functions
* malloc()
* free()
* strcpy()
* printf()

#### C POSIX Library

##### Headers
* signal.h
* pthread.h
* socket.h

##### Functions
* pthread_create()
* raise()
* kill()
* signal()
 
#### GNU C Standard Library (glibc)
##### Headers
* execinfo.h
* inotify.h

##### Functions
* inotify_init()
* backtrace()


## Compilers and Standards

### The Compiler
* The compiler is a program that translates your source code into machine code
    * Later in the course we'll talk about the different stages of compilation (ie. Preprocessing, Compiling, Assembly, and Linking)
* While we tend to say things are "platform" dependent, if we are to be truly technical it would be accurate to say they are "compiler dependent."
* The C specification lays out a set of requirements. All a compiler has to do is meet those requirements to be a C compiler.

### An important quote
* From n1570 6.2.5.5: "a 'plain' int object has the natural size suggested by the architecture of the execution environment"
    * Recall my claim above about `int` size, 'natural' is totally left up to the compiler. You can write a compiler that has 47-bit ints, shorts, and longs and it would be standard compliant (albeit silly).

### Standards Compliance

* Compilers are free to add features or **extensions** to the language
    * eg. `gcc` provides inline assembly which is not required by the C specification.
* Using compiler extensions limits the portability of your code as an extension won't necessarily work with a different compiler (or even a different version of the same compiler)
* **POSIX** (Portable Operating System Interface) is a set of standards designed to maintain compatibility between operating systems.
* With respect to C programming an operating system is **POSIX compliant** if it provides and implements the APIs specified by the POSIX standard. Examples include:
    * Mac OS X
    * Linux
    * OpenBSD
    * Solaris
    * Cygwin (sort of)
* If you write POSIX compliant code it should work on any POSIX compliant operating system (in theory).

## Tying this all together
* The point of all this is to say that you need to know more than just the language's syntax and types to be a successful systems programmer. In addition to writing clean, unambiguous code you should be mindful of:
    * Your compiler
    * The version of your compiler
    * The flags you give your compiler
    * Your operating system
    * The version of your operating system
    * The version of the kernel in your operating system
    * Your local implementation of libc
    * The version of the implementation of libc
    * Whether or not you are making safe assumptions
    * If one can even make safe assumptions...

## Miniature Programs
*Code examples used in recitation can be found in `src`. Future code examples will provide a Makefile.*

* `notquiteansi.c` - You think C is hard? Be glad you don't have to write *ANSI C*.
    * *Note: This code will compile and run given the right set of compiler flags.*
    * Read the code before trying to compile and run it.
    * *Note: The gcc man page is long but it contains a wealth of information.*
    * Compile using the different commands as specified below. Compare the output:
    
        1. `gcc notquiteansi.c -o not_quite_ansi_c`
        * `gcc -Wall notquiteansi.c -o not_quite_ansi_c`
        * `gcc -Wall -pedantic notquiteansi.c - o not_quite_ansi_c`
            * The pedantic flag turns on warnings for proprietary compiler extensions.
            * Apparently there are quite a number of them in use (eg. stuff that's not in the ANSI C spec)
    * **The compiler gives you some hints about the right flag(s) you might need to add to get this to compile...  **   

## Notes on pa1
* **Project Deadline extended to 11:55pm on February 11th**

* What is with you guys and linked lists?

### Libraries

* These headers contain functions that may be useful for pa1. Be sure to check out their man pages and play around with some of the functions.

* `stdlib.h`
* `stdio.h`
* `ctype.h`
