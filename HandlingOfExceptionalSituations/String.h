#pragma once
#include <stdexcept>

class String {
private:
    char* str;
    size_t size;

public:
    class StringMemoryException : public std::runtime_error {
    public:
        StringMemoryException() : std::runtime_error("Memory allocation failed") {}
    };

    class StringInvalidInputException : public std::invalid_argument {
    public:
        StringInvalidInputException(const char* message) : std::invalid_argument(message) {}
    };

    class StringEmptyException : public std::runtime_error {
    public:
        StringEmptyException() : std::runtime_error("Operation on empty string") {}
    };

    String();
    explicit String(size_t customSize);
    String(const char* input);
    String(const String& other);
    ~String();

    void input();
    void output() const;
    size_t length() const;
    bool empty() const;
};