#pragma once

#include <iostream>
#include <exception>

using namespace std;

//invalid matrix size exception class.
class invalid_vector_size_exception : public exception {
public:
    const char* what() const noexcept override {
        return "invalid vector size.";
    }
};