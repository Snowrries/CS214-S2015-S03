CS214 S03 -- Recitation 03
===============
## A quiz of sorts...
* **Is there anything wrong with this code: `struct *somestruct = malloc(sizeof(somestruct*))`?**
    * Indirect (asterisk) on a type name.
    * No variable name
    * Mallocing the size of a pointer instead of a type.
    * Assuming `somestruct` isn't typedef'd, "`somestruct`" is invalid
    * Probably more...
* **Wha are the functional differences between `calloc` and `malloc`?**
    * A call to `calloc` returns a pointer to memory that has been cleared (zero'd out). Malloc makes no such guarantees.
* **Why wouldn't you use one over the other?**    
    * While calloc guarantees you zeroed memory that doesn't come without a cost.
* **What is a pointer?**
    * A pointer is a type whose r-value (contents) provides a reference (location in memory) to an entity of the referenced type
* **What is the size of a pointer?**
    * It depends on the compiler
* Is it safe to cast between pointers?

## Minature Programs

### some_strings
* `some_strings.c`
    * What is sizeof(string1)?
    * What is sizeof(string2)?
    * Presumably both functions return the same thing inside `printStrings`?
    * Given what we just saw, the behavior should be very predictable right?
    
### funcptrs
* A simple demo of function pointers
