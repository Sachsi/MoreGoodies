#pragma once
#include <iostream>
#include <memory>

class Singleton {
public:
    
    // Public method to access the single instance
    static Singleton& getInstance() {
        static Singleton instance;// Guaranteed to be thread-safe in C++11 and later
        return instance;
    }

    // Example method
    void showMessage() {
        std::cout << "Singleton instance accessed!" << std::endl;
    }

    // Delete copy constructor and assignment operator to prevent duplication
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Private constructor to prevent instantiation
    
    Singleton() {
        std::cout << "Singleton instance created!" << std::endl;
    }
};