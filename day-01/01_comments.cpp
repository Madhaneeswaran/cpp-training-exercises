// Single-line comment: the compiler ignores everything after "//" on this line.

/*
   Multi-line comment.
   Everything between the slash-star and star-slash is ignored,
   even across many lines.
*/

#include <iostream>

int main() {
    // TODO(1): Write a comment above this line explaining what std::cout does.
    // what std::cout does is it prints the text to the console.
    std::cout << "Hello, comments!" << std::endl;

    /* TODO(2): Turn the next line into a comment WITHOUT deleting it,
       so it never runs. Use either style. Then compile+run and confirm
       "Line B" never prints. */
    /* std::cout << "Line B: I should be silenced." << std::endl; */

    // TODO(3): This next line has a bug. Comment it out (don't delete it),
    // fix it in a copy below it, and compare.
    std::cout << "Broken" << std::end;   // <-- note: std::end is wrong
    std::cout << "Fixed version" << std::endl;  // <-- note: std::endl is correct

    return 0;
}

/*
   EXPERIMENT: comments are NOT free at compile time in one specific way —
   they can hide bugs. Try this: comment out the `return 0;` line above
   and recompile. Does it still work? Why do you think that is?
   (Hint: look up "implicit return 0 in main" in C++.)
*/
