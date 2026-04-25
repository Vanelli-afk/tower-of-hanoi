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
    size_t max_size; // 0 significa sem limite

    // Inicializa a pilha com tamanho maximo (0 = sem limite)
    void init(size_t max) {
        top = nullptr;
        count = 0;
        max_size = max;
    }

    // Libera todos os nos alocados
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

    // Verifica se a pilha esta vazia
    bool empty() {
        return count == 0;
    }

    // Verifica se a pilha esta cheia
    bool is_full() {
        if (max_size == 0) {
            return false;
        }
        return count >= max_size;
    }

    // Retorna a quantidade de elementos na pilha
    size_t size() {
        return count;
    }

    // Insere elemento no topo
    bool push(T value) {
        if (is_full()) {
            return false;
        }

        Node<T>* node = new Node<T>{value, top};
        top = node;
        count++;
        return true;
    }

    // Remove elemento do topo e salva em out_value
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

    // Retorna o elemento do topo sem remover
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