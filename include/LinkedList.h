#pragma once

#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <vector>
#include <utility>

namespace ll {

    // Singly-linked list node (int payload for interview simplicity)
    struct Node {
        int value = 0;
        Node* next = nullptr;

        explicit Node(int v, Node* n = nullptr) : value(v), next(n) {}
    };

    // A tiny RAII wrapper to avoid leaks in tests / demos.
    // Not copyable (simple ownership), movable.
    class List {
    public:
        List() = default;

        List(std::initializer_list<int> init) {
            for (int v : init) push_back(v);
        }

        ~List() { clear(); }

        List(const List&) = delete;
        List& operator=(const List&) = delete;

        List(List&& other) noexcept : head_(other.head_) { other.head_ = nullptr; }
        List& operator=(List&& other) noexcept {
            if (this != &other) {
                clear();
                head_ = other.head_;
                other.head_ = nullptr;
            }
            return *this;
        }

        Node* head() const { return head_; }

        void set_head(Node* h) { head_ = h; }

        void push_back(int v) {
            Node* n = new Node(v);
            if (!head_) {
                head_ = n;
                return;
            }
            Node* cur = head_;
            while (cur->next) cur = cur->next;
            cur->next = n;
        }

        std::vector<int> to_vector() const {
            std::vector<int> out;
            const Node* cur = head_;
            while (cur) {
                out.push_back(cur->value);
                cur = cur->next;
            }
            return out;
        }

        std::size_t size() const {
            std::size_t count = 0;
            const Node* cur = head_;
            while (cur) { ++count; cur = cur->next; }
            return count;
        }

        void clear() noexcept {
            Node* cur = head_;
            while (cur) {
                Node* next = cur->next;
                delete cur;
                cur = next;
            }
            head_ = nullptr;
        }

    private:
        Node* head_ = nullptr;
    };

    /**
     * TODO (Interview Task):
     * Reverse a singly linked list in-place and return the new head.
     *
     * Requirements:
     * - O(n) time, O(1) extra space
     * - Must work for: empty list, 1 node, many nodes
     * - No memory allocations
     */
    inline Node* reverse(Node* head) {
        // ======= YOUR IMPLEMENTATION HERE =======
        // Hint:
        // Node* prev = nullptr;
        // Node* cur = head;
        // while (cur) { ... }
        (void)head;
        return nullptr; // Deliberately wrong: tests should fail until implemented.
    }

    /**
     * Optional extension (if interviewer asks):
     * Detect cycle using Floyd's algorithm (Tortoise/Hare).
     */
    inline bool has_cycle(const Node* head) {
        const Node* slow = head;
        const Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

} // namespace ll
