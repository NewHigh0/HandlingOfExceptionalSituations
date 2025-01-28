#include "Array.h"
#include <iostream>

void Array::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}

Array::Array() : data(nullptr), size(0) {}

Array::Array(size_t n) : size(n) {
    if (n == 0) {
        throw ArrayInvalidArgumentException("Array size cannot be zero");
    }

    try {
        data = new int[size] {0};
    }
    catch (const std::bad_alloc&) {
        throw ArrayMemoryException();
    }
}

Array::Array(size_t n, int min, int max) : size(n) {
    if (n == 0) {
        throw ArrayInvalidArgumentException("Array size cannot be zero");
    }
    if (min > max) {
        throw ArrayInvalidArgumentException("Minimum value cannot be greater than maximum value");
    }

    try {
        data = new int[size];
    }
    catch (const std::bad_alloc&) {
        throw ArrayMemoryException();
    }

    fillRandom(min, max);
}

Array::Array(size_t n, int x) : size(n) {
    if (n == 0) {
        throw ArrayInvalidArgumentException("Array size cannot be zero");
    }

    try {
        data = new int[size];
    }
    catch (const std::bad_alloc&) {
        throw ArrayMemoryException();
    }

    for (size_t i = 0; i < size; ++i) {
        data[i] = x;
    }
}

Array::Array(const Array& other) : size(other.size) {
    if (other.size == 0) {
        data = nullptr;
        return;
    }

    try {
        data = new int[size];
    }
    catch (const std::bad_alloc&) {
        throw ArrayMemoryException();
    }

    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Array::~Array() {
    clear();
}

void Array::display() const {
    if (empty()) {
        throw ArrayEmptyException();
    }

    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void Array::fillRandom(int min, int max) {
    if (min > max) {
        throw ArrayInvalidArgumentException("Minimum value cannot be greater than maximum value");
    }
    if (empty()) {
        throw ArrayEmptyException();
    }

    for (size_t i = 0; i < size; ++i) {
        data[i] = rand() % (max - min + 1) + min;
    }
}

void Array::resize(size_t newSize) {
    if (newSize == 0) {
        throw ArrayInvalidArgumentException("New size cannot be zero");
    }

    int* newData = nullptr;
    try {
        newData = new int[newSize] {0};
    }
    catch (const std::bad_alloc&) {
        throw ArrayMemoryException();
    }

    if (data != nullptr) {
        size_t minSize = (size < newSize) ? size : newSize;
        for (size_t i = 0; i < minSize; ++i) {
            newData[i] = data[i];
        }
    }

    delete[] data;
    data = newData;
    size = newSize;
}

void Array::sort() {
    if (empty()) {
        throw ArrayEmptyException();
    }

    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int Array::getMin() const {
    if (empty()) {
        throw ArrayEmptyException();
    }

    int minValue = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] < minValue) {
            minValue = data[i];
        }
    }
    return minValue;
}

int Array::getMax() const {
    if (empty()) {
        throw ArrayEmptyException();
    }

    int maxValue = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }
    return maxValue;
}

bool Array::empty() const {
    return size == 0 || data == nullptr;
}