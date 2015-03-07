CS214 S03 -- Recitation 04
===============
## PA1 - Tokenzier
* Grading will commence shortly.

## PA2 - Sorted List
* Due on **2/25 at 5:00PM**
* **Pay close attention to whitespace when writing makefiles.**

***

## A quiz of sorts...

* **Why should we never use the `strcpy` function?**
    * Short answer, buffer overflows. Long answer below.
        
* **What functions can we use instead?**
    * `strncpy`, `memcpy`, `memmove`, `strlcpy` (not in ISO libc or POSIX)
    
* **Is it safe to cast between pointers?**
    * It's safe to cast between *pointers to data*. It's also to safe to cast between **pointers to functions**. It is **not safe to cast a pointer to data to a function pointer or vice versa** because they are NOT guaranteed to be the same size.

## More recommended reading

### Makefiles
* [GNU Make Manual](https://www.gnu.org/software/make/manual/)
    * Sections 2 and 3 are great for getting started
* **Managing Projects with GNU Make 3rd Edition** - Mecklenburg
    * An advanced resource

##### PLEASE READ SECTION 2.1-2.4 CAREFULLY.


A **recipe** is an action that make carries out. A recipe may have more than one command, either on the same line or each on its own line. ***Please note: you need to put a tab character at the beginning of every recipe line!*** This is an obscurity that catches the unwary. If you prefer to prefix your recipes with a character other than tab, you can set the .RECIPEPREFIX variable to an alternate character (see Special Variables).

### Source Code
* Reading documentation is an immensely important skill that many students (and burgeoning software developers) lack. Reading source written by others is also an equally important skill.
* You have 
* A recurring theme is going to be reading source code The beauty of C is it's simplicity, there's nothing in the language 

## On Copying Strings

### strcpy

I often assert you should ***never*** use `strcpy` but why?

***READ THE MAN PAGE:***


```
If  the  destination  string of a strcpy() is not large enough, then anything might
happen.  Overflowing fixed-length string buffers is a  favorite  cracker  technique
for  taking  complete  control  of the machine.  Any time a program reads or copies
data into a buffer, the program first needs to check  that  there’s  enough  space.
This  may  be unnecessary if you can show that overflow is impossible, but be care-
ful: programs can get changed over time, in ways that may make the impossible  pos-
sible.
```

So, truthfully there are totally times where you can use it; if you can guarantee your input is a valid string and you know your output buffer is big enough to hold it (typically you wrap a call to `strcpy` with code that does this) it's as safe as anything else. That said, by now you should have the C chops to look at the implementation and decide how you feel for yourself.

 
* Let's take a look at the [ strcpy implementation used in libc on OS X](http://opensource.apple.com/source/Libc/Libc-1044.1.2/string/strcpy.c).
    * Pretty simple stuff. Get the size from `strlen` and `memcpy` that many bytes from src to dst. We still don't know why this is dangerous. It makes two function calls, let's take a look there.
    * We call `strlen` but how does that work? Digging through the tree we see that the [strlen implementation used in OS X](http://opensource.apple.com/source/Libc/Libc-1044.1.2/string/FreeBSD/strlen.c) is actually borrowed from FreeBSD.
    * There's a bunch of cool stuff going on here. In particular look at how they've implemented checking for zero (the rational provided in a comment at the top).
    * Note that the function has a return statement but a comment specifying that it will never be reached. Why is that (hint, when does that second for loop terminate)?
    * What we can see here is that (at least in this implementation), **the issue is not actually with `strcpy` but technically with `strlen` in that the latter will read bytes possibly beyond your buffer and possibly forever.**
    
### What about strncpy?
`strncpy` is a little safer but it's a bit silly in that it doesn't guarantee we will return a proper string (that is a series of chars with a null byte at the end).

* Once more let's refer to [strncpy on libc on OS X](http://opensource.apple.com/source/Libc/Libc-1044.1.2/string/strncpy.c). Note that we are passing in another argument specifying the maximum length of the buffer.
    * A titch more complicated but still pretty clean. We use `strnlen` to find the length of the string but we then **check it against the maxlen argument passed**. If the string is less than the buffer size, we pad the rest with zeros using `memset`. If it's the same size (or bigger) than maxlen, we copy up to maxlen bytes (with or without a null byte).
        * Note that `strnlen` behaves a bit differently from `strlen` as seen in [the source code](http://opensource.apple.com/source/Libc/Libc-1044.1.2/string/FreeBSD/strnlen.c). Much easier to read than strlen but also lacking fancy loop reducing operations.
    
### I've seen/heard about strlcpy...
`strlcpy` is a fairly nice function in that it always guarantees a null byte is placed at the end of the length. The source for [strlcpy in libc on OS X](http://opensource.apple.com/source/Libc/Libc-1044.1.2/string/strlcpy.c) demonstrates this.


### Ok ok, so then what should I use?
That depends; In general I like `memcpy` because it's in ANSI C and it's explicit about its behavior. That said you being a cowboy is bad and typically you should follow the conventions of whatever code base you are contributing to.

At the end of the day it's actually extreme to say one should never use `strcpy`. I've also failed to address a number of issues including the speed and or optimizations of these functions (in code, at compiler time, or even at the architecture level).

**The big takeaway here is that, technically speaking, any and every function is safe within it's design parameters. Functions aren't inherently unsafe however it's up to people to know how to use them safely.**

### More notes
An interesting side note, the manpages for all the string copying functions claim that it is undefined to copy strings into overlapping memory regions. Why is this? *Hint: what's the difference between `memcpy` and `memmove` and why do we have both functions?*

It's up to a software developer determine if it's safe to use `strcpy`. As far as I can tell `strncpy` was really only introduced because the language maintainers came to believe that software developers were too stupid to be relied upon to write boilerplate checks around calls to `strcpy`. The BSD people added `strlcpy` to the mix because they thought it was silly strncpy had to be wrapped with more code (code to insure the copied string was null terminated). For whatever reason the GNU libc maintainers refuse to add it to glibc (contrast this with the fact that the Linux kernel have their own version that they use). 


### Some irrelevant notes on optimization
* This discussion is not meant to talk about the speed or efficiency of any of these functions, simply their functional "safety". 
* Fun fact, the versions of strcpy and strncpy shown here aren't even used if you compile OS X libc for x86 or x86_64. On those platforms there are special [hand written assembly](http://opensource.apple.com/source/Libc/Libc-1044.1.2/x86_64/string/) implementations.


### So strcpy is sort of ok sometimes, what about gets?
# NEVER USE GETS, NO REALLY DON'T DO IT

## More on Casting Pointers
    * Recall that C isn't a language designed for x86 or really any particular architecture.
    * This isn't one of those "weird edge cases that you'll practically never encounter in the real world" (eg. 9-bit bytes). 

    * What are the differences between a von Neumann and Harvard architectures?
    * Microchip PIC18 microcontrollers use 8-bit addressing in program memory while instructions are 16-bits wide. 


## Miniature Programs

### iter_test
* **Full disclosure I don't claim to know jack about C++**
* A simple program written to demonstrate how the behavior of your sorted list iterators is *similar* to that of C++ STL iterators.
* Fun fact, I wrote this on my laptop assuming C++11 would be supported on the ilabs... Oh how wrong I was... and oh how this code had to be entirely refactored to work with C++03...