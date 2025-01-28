#pragma once
#include <stdexcept>

class Array {
private:
    int* data;
    size_t size;
    void clear();

public:
    class ArrayEmptyException : public std::runtime_error {
    public:
        ArrayEmptyException() : std::runtime_error("Operation on empty array") {}
    };

    class ArrayMemoryException : public std::runtime_error {
    public:
        ArrayMemoryException() : std::runtime_error("Memory allocation failed") {}
    };

    class ArrayInvalidArgumentException : public std::invalid_argument {
    public:
        ArrayInvalidArgumentException(const char* message) : std::invalid_argument(message) {}
    };

    Array();
    Array(size_t n);
    Array(size_t n, int min, int max);
    Array(size_t n, int x);
    Array(const Array& other);
    ~Array();

    void display() const;
    void fillRandom(int min, int max);
    void resize(size_t newSize);
    void sort();
    int getMin() const;
    int getMax() const;
    bool empty() const;
    size_t getSize() const { return size; }
};