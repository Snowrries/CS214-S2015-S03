CS214 S03 -- Recitation 05
===============

## Announcements
### PA1 Grades on the way...
### PA2 is closed...
### PA3 is coming (for you)...

***

## A quiz of sorts
* **What are the differences between `open` and `fopen`?**
    * `open` is a system call. 
    * `fopen` is a library function. 
    * There's more to this but that's not the topic for today.
* **What are O_RDONLY, WRONLY, O_RDWR?**
    * Macro Definitions
* **No really, what are they?**
    * Numbers (octal to be precise)
* **What is an opaque type?**
    * A type who's internal specification is hidden to the user. This allows for portability in implementation or encapsulation (we're almost sounding object oriented here).
* **What is the size of an opaque type?**
    * That depends; if we have an opaque pointer (eg. a `void *`) we can't use sizeof so we can't tell.
* What is the size of a pointer to an opaque type?

## Compilation - For Realsies

What we refer to as compilation is actually four discrete processes rolled into one. I went over more detail in recitation so below is a fast and dirty summary of what you should know for now.

### Preprocessing

The **preprocessor** is a parser that expands macros, handles directives (eg. file inclusion), removes comments, and handles compilation conditionals. 

* Compile with `-E` to stop gcc after preproccessing.
* The preprocessor does a fairly simple form of text replacement, **you must be very careful with macro definitions/functions**
* The preprocessor takes C source and outputs C source.

#### Examples

* **Macro definitions** -- When you `#define <identifier> <replacement>` the preprocessor goes through and flat replaces the specified identifier with. You can define macros that look like functions though one has to be **very careful** with this.
* **Inclusion** -- When you `#include`, the preprocessor quite literally copies the contents of the file specified into your file at the line where you included it.
* **Conditional Compilation** -- You can use `#if`, `#ifdef`, `#ifndef`, etc to control whether or not certain blocks of code make it to the source produced by the preprocessor

### Compilation

The **compiler** takes the output of the preprocessor and generates architecture specific assembly. Compiling is a complex operation as C source code must be "translated" to assembly using a slew of rules and parsing techniques. It is because of this because of this that different compilers will often produce very different assembly given the same code. Note that the assembly produced is only that for what you have implemented in that compilation unit not functions you call from other libraries.

* Compile with `-S` to stop gcc after compilation.
* The various `-O` flags change the level of optimization the compiler will attempt.
* The compiler takes C source code and produces assembly (asm).


### Assembly
The **assembler** takes the assembly and assembles it into an object file. Object files are binary files that contain your compiled machine code as well as metadata related to debugging and linking. Note that there are different systems use different object files. The objects assembled on Linux won't necessarily work on OS X because they use different object formats. 

* Compile with `-c` to stop gcc after assembly.
* Different operating systems use different object file formats. There is a lot of interesting history here that pertains to various design decisions in different operating systems.

#### Some common object file formats

* **a.out** - The binary produced by Ken Thompson's PDP-7 assembler in the late '60s. Used up until recently in numerous operating systems (FreeBSD until 1998, OpenBSD until 2003).
* **ELF** - The *Executable and Linkable Format* is a widely used object file format. The following systems (among others) utilize ELF: 
    * Linux
    * Most *BSDs
    * Solaris
    * The Playstation 2/3/4
    * GameCube/Wii
    * Android
* **Mach-O** - A binary format historically used by operating systems based on the Mach kernel (OS X, iOS, NeXTSTEP)


### Linking
The **linker** is responsible for taking objects and combining (linking) them into a single executable file. It is at this stage that you pull in the various dependancies your code needs (eg. library functions, system calls, etc).

* **Static Linking** is where you resolve (link) dependancies at compile time.
    * The linker looks through various directories (specified by default and by using compiler flags) for libraries.
    * Use the `-l<library>` flag with gcc to search for the specified library. *Note - the -l flag surrounds the specified with 'lib' and '.a'. Eg, the above would search for a library `liblibrary.a`*
    * Use the `-l <library>` flag with gcc to search a specified object file for a particular symbols.
    * Use the `-L<dir>` flag with gcc to add a a directory to the list of directories searched for libraries. *Note - there is no space between L and the dir specified*
* Note that the linker searches libraries in the order they are specified.`   


* **Dynamic Linking** is where you link in dependancies at run-time (ie. when you start a program)

### Miniature Programs

#### compileme and mylib
* A simple program used to demonstrate the various stages of compilation.
* This example has at least one bug in it, finding it is a good exercise.
* Try compiling both the library and the executable with the above flags.
