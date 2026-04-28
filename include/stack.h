#ifndef STACK_H
#define STACK_H

#include <cstddef>

template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template <typename T>
struct Stack {
    Node<T>* top;
    size_t count;
    size_t max_size; 

    void init(size_t max) {
        top = nullptr;
        count = 0;
        max_size = max;
    }

    void destroy() {
        Node<T>* current = top;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        top = nullptr;
        count = 0;
    }

    bool empty() {
        return count == 0;
    }

    bool is_full() {
        if (max_size == 0) {
            return false;
        }
        return count >= max_size;
    }

    size_t size() {
        return count;
    }

    bool push(T value) {
        if (is_full()) {
            return false;
        }

        Node<T>* node = new Node<T>{value, top};
        top = node;
        count++;
        return true;
    }

    bool pop(T* out_value) {
        if (empty()) {
            return false;
        }

        Node<T>* node = top;
        if (out_value != nullptr) {
            *out_value = node->value;
        }
        top = node->next;
        delete node;
        count--;
        return true;
    }

    bool peek(T* out_value) {
        if (empty()) {
            return false;
        }
        if (out_value != nullptr) {
            *out_value = top->value;
        }
        return true;
    }
};

#endif