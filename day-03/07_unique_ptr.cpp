#include <iostream>
#include <memory>   // unique_ptr, shared_ptr, weak_ptr all live here

// unique_ptr AUTOMATES the new/delete pairing from 04_new_delete.cpp.
// It "owns" one heap object, and deletes it automatically when the
// unique_ptr itself goes out of scope -- no matter how the function exits
// (normal return, early return, even an exception). This is called RAII:
// Resource Acquisition Is Initialization. You'll see this word a lot.

// PREVIEW: `struct` is properly covered in 13_struct.cpp -- you haven't hit
// it yet, so here's a quick line-by-line translation of the syntax below,
// just so it isn't a mystery:
//
//   struct Resource { ... };     "Resource" is a new type, like int or
//                                 std::string, but one YOU get to define.
//   int id;                      it holds one piece of data: a whole number.
//   Resource(int i) : id(i) {..} the CONSTRUCTOR: runs automatically the
//                                 moment a Resource is created. `: id(i)`
//                                 just means "set this Resource's id to
//                                 whatever int was passed in". The `{ }`
//                                 body then runs -- here, just a print.
//   ~Resource() { .. }           the DESTRUCTOR (note the `~`): runs
//                                 automatically the moment a Resource is
//                                 destroyed. That's the part unique_ptr
//                                 calls FOR you, which is the whole point
//                                 of this file.
//
// Everything below this only cares about those two things happening
// automatically -- CREATED when made, DESTROYED when unique_ptr cleans up.
struct Resource {
    int id;
    Resource(int i) : id(i) { std::cout << "  Resource " << id << " CREATED\n"; }
    ~Resource() { std::cout << "  Resource " << id << " DESTROYED\n"; }
};

void ownsAResource() {
    std::cout << "--- entering ownsAResource() ---\n";
    std::unique_ptr<Resource> res = std::make_unique<Resource>(1);
    std::cout << "  using res, id = " << res->id << "\n";
    std::cout << "--- leaving ownsAResource() (no delete written anywhere!) ---\n";
} // <-- res goes out of scope HERE, and its destructor calls `delete` for you

int main() {
    std::cout << "--- simplest case first: unique_ptr<int>, no class involved ---\n";
    std::unique_ptr<int> p = std::make_unique<int>(42);
    std::cout << "*p = " << *p << "  (dereference it just like a raw pointer)\n";
    // no delete anywhere -- p frees the int automatically when it goes out of scope

    std::cout << "\n--- this replaces the manual new/delete pattern from 04_new_delete.cpp ---\n";
    int* raw = new int(42);
    std::cout << "*raw = " << *raw << "\n";
    delete raw;   // forget this line, or return early before reaching it, and you leak
    raw = nullptr;

    std::cout << "\n--- a default-constructed unique_ptr is EMPTY (holds nullptr) ---\n";
    std::unique_ptr<int> empty;
    std::cout << "empty is " << (empty ? "non-empty" : "empty") << "  (check it like a bool)\n";

    std::cout << "\n--- now with a type that PRINTS its own construction/destruction, ---\n"
              << "--- so you can *see* the automatic cleanup happen ---\n";
    ownsAResource();
    std::cout << "back in main -- notice 'Resource 1 DESTROYED' already printed above,\n"
              << "automatically, the instant ownsAResource() returned.\n";

    std::cout << "\n--- unique_ptr CANNOT be copied (exclusive ownership) ---\n";
    std::unique_ptr<Resource> a = std::make_unique<Resource>(2);
    // TODO: uncomment the next line. Two unique_ptrs both "owning" (and
    // later both trying to delete) the SAME object would double-delete it
    // -- undefined behavior. The compiler forbids this outright at compile
    // time instead of letting you crash at runtime.
    // std::unique_ptr<Resource> b = a;   // compiler error: copy constructor deleted

    std::cout << "\n--- but it CAN be MOVED (ownership transfers, doesn't duplicate) ---\n";
    std::unique_ptr<Resource> c = std::move(a);   // ownership moves from a to c
    std::cout << "after std::move: a is now " << (a ? "still owns something" : "EMPTY")
              << "  <-- PREDICT: did 'a' keep its Resource, or lose it?\n";
    std::cout << "c->id = " << c->id << "  (c is the new, sole owner)\n";

    std::cout << "\n--- accessing safely: check before use, just like nullptr ---\n";
    if (a) {
        std::cout << "a->id = " << a->id << "\n";
    } else {
        std::cout << "a is empty, skipping safely (this is the branch that runs)\n";
    }

    std::cout << "\n--- end of main: 'c' will be destroyed automatically now ---\n";
    return 0;
}

/*
   HISTORICAL NOTE (Day_03.md's "Auto Pointer" row): `std::auto_ptr` was an
   EARLIER attempt at this same idea, but it had a dangerous flaw --
   copying an auto_ptr (with plain `=`, not std::move) SILENTLY transferred
   ownership and left the original one broken, with no compiler error to
   warn you. It's been fully removed as of C++17 (you can't even compile
   `std::auto_ptr` anymore) precisely because unique_ptr fixes that flaw by
   making copying a compile ERROR and requiring the explicit `std::move`
   you just used above.
*/
