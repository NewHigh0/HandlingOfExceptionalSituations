#include <iostream>
#include "List.h"
#include "Array.h"
#include "String.h"

int main() {
    /*List<int> myList;

    try {
        myList.push_back(10);
        myList.push_back(20);
        myList.push_front(5);

        std::cout << "Front: " << myList.front() << std::endl;
        std::cout << "Back: " << myList.back() << std::endl;

        myList.pop_front();
        std::cout << "Pop_front, front: " << myList.front() << std::endl;

        myList.pop_back();
        std::cout << "Pop_back, back: " << myList.back() << std::endl;

        myList.clear();
        std::cout << "Is empty: " << myList.empty() << std::endl;

        std::cout << "\nTesting exceptions:" << std::endl;

        std::cout << "Trying to access empty list..." << std::endl;
        myList.front();
    }
    catch (const List<int>::ListEmptyException& e) {
        std::cout << "Caught empty list exception: " << e.what() << std::endl;
    }
    catch (const List<int>::ListMemoryException& e) {
        std::cout << "Caught memory allocation exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught standard exception: " << e.what() << std::endl;
    }*/

    /*try {
        Array arr1(5);
        std::cout << "Empty array: ";
        arr1.display();

        Array arr2(10, 2, 100);
        std::cout << "Random array: ";
        arr2.display();

        Array arr3(7, 42);
        std::cout << "Array with value 42: ";
        arr3.display();

        arr2.sort();
        std::cout << "Sorted array: ";
        arr2.display();
        std::cout << "Min: " << arr2.getMin() << std::endl;
        std::cout << "Max: " << arr2.getMax() << std::endl;

        arr2.resize(15);
        std::cout << "Resized array: ";
        arr2.display();

        std::cout << "\nTesting exceptions:" << std::endl;

        try {
            Array invalidSize(0);
        }
        catch (const Array::ArrayInvalidArgumentException& e) {
            std::cout << "Caught invalid size exception: " << e.what() << std::endl;
        }

        try {
            Array invalidRange(5, 100, 1);
        }
        catch (const Array::ArrayInvalidArgumentException& e) {
            std::cout << "Caught invalid range exception: " << e.what() << std::endl;
        }

        try {
            Array emptyArr;
            emptyArr.getMin();
        }
        catch (const Array::ArrayEmptyException& e) {
            std::cout << "Caught empty array exception: " << e.what() << std::endl;
        }
    }
    catch (const Array::ArrayMemoryException& e) {
        std::cout << "Caught memory allocation exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught unexpected exception: " << e.what() << std::endl;
    }*/

    try {
        String defaultString;
        try {
            defaultString.input();
            defaultString.output();
        }
        catch (const String::StringInvalidInputException& e) {
            std::cout << "Input error: " << e.what() << std::endl;
        }

        String customString(static_cast<size_t>(50));
        try {
            customString.input();
            customString.output();
        }
        catch (const String::StringInvalidInputException& e) {
            std::cout << "Input error: " << e.what() << std::endl;
        }

        String initializedString("Hello, World!");
        initializedString.output();
        std::cout << "Length: " << initializedString.length() << std::endl;

        String copiedString(initializedString);
        copiedString.output();

        std::cout << "\nTesting exceptions:" << std::endl;

        try {
            String invalidSize(static_cast<size_t>(0));
        }
        catch (const String::StringInvalidInputException& e) {
            std::cout << "Invalid size exception: " << e.what() << std::endl;
        }

        try {
            String emptyString("");
        }
        catch (const String::StringInvalidInputException& e) {
            std::cout << "Empty string exception: " << e.what() << std::endl;
        }

        try {
            String nullString(nullptr);
        }
        catch (const String::StringInvalidInputException& e) {
            std::cout << "Null string exception: " << e.what() << std::endl;
        }
    }
    catch (const String::StringMemoryException& e) {
        std::cout << "Memory allocation error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}