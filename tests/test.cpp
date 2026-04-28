#include "stack.h"
#include <cassert>
#include <iostream>

// Helper: safe move with rule validation
static void safe_move(Stack<int>& from, Stack<int>& to) {
    int disk, topDest;

    assert(from.peek(&disk)); // must have a disk

    if (to.peek(&topDest)) {
        assert(disk < topDest); // rule: smaller on larger
    }

    assert(from.pop(&disk));
    assert(to.push(disk));
}

// Hanoi implementation only for testing (no prints)
static void hanoi_test(int n, Stack<int>& origin, Stack<int>& aux, Stack<int>& dest, int& moves) {
    if (n <= 0) return;

    hanoi_test(n - 1, origin, dest, aux, moves);

    safe_move(origin, dest);
    moves++;

    hanoi_test(n - 1, aux, origin, dest, moves);
}

// Check if stack is correctly ordered (1 on top, increasing downward)
static void check_stack_order(Stack<int>& s, int expected_size) {
    Stack<int> temp;
    temp.init(0);

    int prev = 0;
    int value = 0;
    int count = 0;

    while (s.pop(&value)) {
        temp.push(value);
        if (count > 0) {
            assert(value > prev); // increasing order downward
        }
        prev = value;
        count++;
    }

    assert(count == expected_size);

    // restore original stack
    while (temp.pop(&value)) {
        s.push(value);
    }

    temp.destroy();
}

static void test_hanoi_n(int n) {
    Stack<int> a, b, c;
    a.init(0); 
    b.init(0); 
    c.init(0);

    // initialize stack A
    for (int i = n; i >= 1; i--) {
        assert(a.push(i));
    }

    int moves = 0;

    hanoi_test(n, a, b, c, moves);

    // 1. check number of moves
    int expected = (1 << n) - 1;
    assert(moves == expected);

    // 2. final state
    assert(a.empty());
    assert(b.empty());
    assert(c.size() == (size_t)n);

    // 3. correct order
    check_stack_order(c, n);

    a.destroy();
    b.destroy();
    c.destroy();
}

int main() {
    test_hanoi_n(1);
    test_hanoi_n(2);
    test_hanoi_n(3);
    test_hanoi_n(4);
    test_hanoi_n(5);

    std::cout << "All Hanoi tests passed.\n";
    return 0;
}