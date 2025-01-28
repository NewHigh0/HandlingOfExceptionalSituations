#include <iostream>
#include "List.h"

int main() {
    List<int> myList;

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
    }

    return 0;
}