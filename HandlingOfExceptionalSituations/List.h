#pragma once
#include <stdexcept>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& data, Node* next = nullptr, Node* prev = nullptr)
            : data(data), next(next), prev(prev) {}
    };
    Node* head;
    Node* tail;
    size_t size;

public:
    class ListEmptyException : public std::runtime_error {
    public:
        ListEmptyException() : std::runtime_error("Operation on empty list") {}
    };

    class ListMemoryException : public std::runtime_error {
    public:
        ListMemoryException() : std::runtime_error("Memory allocation failed") {}
    };

    List();
    ~List();
    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    T& back() const;
    T& front() const;
    void clear();
    bool empty() const;
    size_t get_size() const { return size; }
};