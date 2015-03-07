CS214 S03 -- Recitation 06
===============

## Announcements
### PA1 grades released
* Stats and grader contact info on Sakai



### PA2 grades on the Way
### PA3 is due on Wednesday

***

## A quiz of sorts
* **Why do they close the university for this paltry amount of snow?**
    * Because they don't know how to plow the roads and no one around here knows how to drive.
* **Why do they close the unversity on the day I have classes I enjoy?**
    * ???
* **How many people will show up to these office hours?**
    * 3
    
## PA3 Tips
This assignment is (by design) much more complex than the previous ones so I hope you've all started early. Future assignments will be much harder than this one.

* Dr. Russell has posted a handful of helpful hints on Sakai.
* Break the program down into discrete components componant. Use what you know about C program struction and compilation to do this effectively.
* **THINK BEFORE YOU CODE**
* A solid understanding of data structures is critical for this assignment.

### Testing

#### Functional Correctness
* You can use the `find` command walk your directory structure
    * `find .` will display the file tree from your current directory down.
* You can use the `file` command to determine if a file is ASCII or not
* If you aren't familiar with a debugger (like gdb or lldb) now is probably a good time to fix that.

#### Code Quality
By now you've probably realized that 'code quality' thing on the syllabus is for real. Among other things we test your code for memory leaks and general bad behavior (poor assumptions, poor style, undefined behavior). `valgrind` and `gdb` are useful tools for warning you about the sacriligious aspects of your implementation and digging yourself out of your segfaulting hellscape when your code takes you there respectively.

Stanford has brief tutorials for getting your feet wet with both of these tools. I highly recommend taking a look.

* http://web.stanford.edu/class/cs107/guide_valgrind.html
* http://web.stanford.edu/class/cs107/guide_gdb.html


### Binary Files
Part of this assignment is determining whether or not files are binary or not. For the purposes of our definition a file is considered binary if it is not a "valid ASCII text file." 

How do we determine if a file is binary or not? A file is nothing but a sequence of bytes. We have some arbitrary definition of "not binary" so presumably one can simply scan the file provided and see if meets our definition for not. This is, in fact, what the file command does as seen in [the source](http://www.opensource.apple.com/source/file/file-6/file/src/).


## Reading Source
As a friendly reminder being able to jump into a piece of code and understand it is an invaluable skill. The beauty of C is that it's very explicit and (assuming it's not written in an obfuscating manner) fairly easy to read.

As an exercise take a look at the source code posted above. It's a fairly complicated program but it's not hard to read. Start in `file.c` and see if you can't figure out how `file` determines if a file is ASCII or not. 

### Hints
* That `process` function in `file.c` is a promising place to start.
* There are a handful of header files, looking at them gives you an idea about the functions.
* The names are fairly intuitive. `file.h` probably contains prototypes for functions in `file.c`. `funcs.c` probably contains various helper functions.
* You'll have to jump between files.
 

## Miniature Programs

### isascii
* `isascii.c` contains the code for a simple program that takes the file passed to it determines if it's ASCII or not.
* It contains a number of examples of how to use the various file APIs.
* I did the exact exercise described above and figured out how file determines if a file is ASCII text or not. I then liberated some of the code and created `isascii.c` with it.


**Anyone is free to use this code for pa3 though I warn you there is a glaring inefficiency somewhere in it.**
