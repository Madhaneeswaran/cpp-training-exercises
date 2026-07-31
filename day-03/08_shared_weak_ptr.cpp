#include <iostream>
#include <memory>

struct Resource {
    int id;
    Resource(int i) : id(i) { std::cout << "  Resource " << id << " CREATED\n"; }
    ~Resource() { std::cout << "  Resource " << id << " DESTROYED\n"; }
};

int main() {
    std::cout << "--- shared_ptr: MULTIPLE owners, reference-counted ---\n";
    std::shared_ptr<Resource> a = std::make_shared<Resource>(1);
    std::cout << "use_count right after creation = " << a.use_count()
              << "  <-- PREDICT: how many shared_ptrs point at Resource 1 so far?\n";

    {
        std::shared_ptr<Resource> b = a;   // COPYING a shared_ptr is fine, unlike unique_ptr!
        std::cout << "use_count after copying into b = " << a.use_count()
                  << "  <-- PREDICT: did it go up?\n";
        std::cout << "b->id = " << b->id << " (b and a point at the SAME Resource)\n";
    } // b goes out of scope HERE -- but does Resource 1 get destroyed yet?

    std::cout << "use_count after b went out of scope = " << a.use_count()
              << "  <-- PREDICT: back down, or still up?\n";
    std::cout << "(Resource 1 is only destroyed when the LAST shared_ptr pointing\n"
              << " at it disappears -- that's 'reference counting'.)\n";

    std::cout << "\n--- watch it actually get destroyed ---\n";
    a = nullptr; // this was the last owner
    std::cout << "set a = nullptr -- 'Resource 1 DESTROYED' should have just printed above\n";

    std::cout << "\n--- weak_ptr: look, but don't own ---\n";
    std::shared_ptr<Resource> owner = std::make_shared<Resource>(2);
    std::weak_ptr<Resource> observer = owner;   // does NOT increase use_count
    std::cout << "use_count (weak_ptr doesn't count!) = " << owner.use_count()
              << "  <-- PREDICT: is this 1 or 2?\n";

    std::cout << "\n--- to actually USE a weak_ptr, you must lock() it first ---\n";
    if (std::shared_ptr<Resource> locked = observer.lock()) {
        std::cout << "locked successfully, id = " << locked->id << "\n";
    } else {
        std::cout << "the object is already gone -- lock() returned empty\n";
    }

    std::cout << "\n--- now destroy the real owner, and try again ---\n";
    owner = nullptr;   // 'Resource 2 DESTROYED' should print here
    if (std::shared_ptr<Resource> locked = observer.lock()) {
        std::cout << "locked successfully, id = " << locked->id << "\n";
    } else {
        std::cout << "lock() returned empty -- the Resource is gone, and observer KNOWS it,\n"
                  << "instead of dangling silently like a raw pointer would (06).\n";
    }

    return 0;
}

/*
   WHY weak_ptr EXISTS (Day_03.md: "solves cyclic dependency issues"):
   imagine a Parent holding a shared_ptr to its Child, AND the Child holding
   a shared_ptr back to its Parent. Each keeps the other's use_count at 1
   forever -- neither is EVER destroyed, even if nothing outside them still
   cares. That's a reference-counting deadlock (a memory leak by another
   name). The fix: one direction (usually child -> parent) uses weak_ptr
   instead, which doesn't add to the count, so the cycle can actually break.

   COMPARISON (Day_03.md's last row):
     unique_ptr: ONE owner. Fastest (no counting). Can't be copied, only moved.
     shared_ptr: MANY owners. Slower (atomic reference counting). Use when
                 truly shared, e.g. cached data multiple objects need.
     weak_ptr:   ZERO ownership. Use to observe a shared_ptr'd object
                 without keeping it alive, and without risking a dangling
                 pointer if it's already gone.
   DEFAULT to unique_ptr. Reach for shared_ptr only when you genuinely need
   shared ownership -- it's easy to overuse and pay the extra cost for
   nothing.
*/
