#include "List.h"
template class List<int>;

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
void List<T>::push_back(const T& value) {
    Node* newNode = nullptr;
    try {
        newNode = new Node(value, nullptr, tail);
    }
    catch (const std::bad_alloc&) {
        throw ListMemoryException();
    }

    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
    ++size;
}

template <typename T>
void List<T>::push_front(const T& value) {
    Node* newNode = nullptr;
    try {
        newNode = new Node(value, head, nullptr);
    }
    catch (const std::bad_alloc&) {
        throw ListMemoryException();
    }

    if (head) {
        head->prev = newNode;
    }
    else {
        tail = newNode;
    }
    head = newNode;
    ++size;
}

template <typename T>
void List<T>::pop_back() {
    if (empty()) {
        throw ListEmptyException();
    }

    Node* oldTail = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete oldTail;
    --size;
}

template <typename T>
void List<T>::pop_front() {
    if (empty()) {
        throw ListEmptyException();
    }

    Node* oldHead = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete oldHead;
    --size;
}

template <typename T>
T& List<T>::back() const {
    if (empty()) {
        throw ListEmptyException();
    }
    return tail->data;
}

template <typename T>
T& List<T>::front() const {
    if (empty()) {
        throw ListEmptyException();
    }
    return head->data;
}

template <typename T>
void List<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
bool List<T>::empty() const {
    return size == 0;
}