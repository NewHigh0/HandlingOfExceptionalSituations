#include "String.h"
#include <iostream>
#include <cstring>

String::String() : String(80) {}

String::String(size_t customSize) : size(customSize + 1) {
    if (customSize == 0) {
        throw StringInvalidInputException("String size cannot be zero");
    }

    try {
        str = new char[size];
        str[0] = '\0';
    }
    catch (const std::bad_alloc&) {
        throw StringMemoryException();
    }
}

String::String(const char* input) {
    if (input == nullptr || input[0] == '\0') {
        throw StringInvalidInputException("Input string cannot be null or empty");
    }

    size = strlen(input) + 1;

    try {
        str = new char[size];
        if (strcpy_s(str, size, input) != 0) {
            throw StringInvalidInputException("Failed to copy input string");
        }
    }
    catch (const std::bad_alloc&) {
        throw StringMemoryException();
    }
}

String::String(const String& other) : size(other.size) {
    if (other.empty()) {
        throw StringInvalidInputException("Cannot copy from empty string");
    }

    try {
        str = new char[size];
        if (strcpy_s(str, size, other.str) != 0) {
            throw StringInvalidInputException("Failed to copy string");
        }
    }
    catch (const std::bad_alloc&) {
        throw StringMemoryException();
    }
}

String::~String() {
    delete[] str;
}

void String::input() {
    if (str == nullptr) {
        throw StringMemoryException();
    }

    std::cout << "Enter a String: ";
    if (!std::cin.getline(str, size)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw StringInvalidInputException("Input error or buffer overflow");
    }

    if (strlen(str) == 0) {
        throw StringInvalidInputException("Empty input is not allowed");
    }
}

void String::output() const {
    if (empty()) {
        throw StringEmptyException();
    }
    std::cout << "String: " << str << std::endl;
}

size_t String::length() const {
    if (empty()) {
        throw StringEmptyException();
    }
    return strlen(str);
}

bool String::empty() const {
    return str == nullptr || str[0] == '\0';
}
