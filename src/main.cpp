#include "LinkedList.h"

#include <cassert>
#include <iostream>
#include <vector>

static void expect_eq(const std::vector<int>& got, const std::vector<int>& expected) {
    if (got != expected) {
        std::cerr << "Test failed.\nGot:      ";
        for (int x : got) std::cerr << x << " ";
        std::cerr << "\nExpected: ";
        for (int x : expected) std::cerr << x << " ";
        std::cerr << "\n";
        std::abort();
    }
}

static void test_empty() {
    ll::List list;
    assert(!list.head());
    list.set_head(ll::reverse(list.head()));
    expect_eq(list.to_vector(), {});
}

static void test_single() {
    ll::List list{ 42 };
    assert(list.size() == 1);
    list.set_head(ll::reverse(list.head()));
    expect_eq(list.to_vector(), { 42 });
}

static void test_many() {
    ll::List list{ 1, 2, 3, 4, 5 };
    assert(list.size() == 5);
    list.set_head(ll::reverse(list.head()));
    expect_eq(list.to_vector(), { 5, 4, 3, 2, 1 });
}

static void test_twice_is_original() {
    ll::List list{ 7, 8, 9 };
    auto original = list.to_vector();

    list.set_head(ll::reverse(list.head()));
    list.set_head(ll::reverse(list.head()));

    expect_eq(list.to_vector(), original);
}

int main() {
    // Basic sanity: no cycle in our constructed lists
    {
        ll::List list{ 1,2,3 };
        assert(!ll::has_cycle(list.head()));
    }

    // Reverse tests
    test_empty();
    test_single();
    test_many();
    test_twice_is_original();

    std::cout << "All tests passed.\n";
    return 0;
}
