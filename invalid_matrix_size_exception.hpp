#pragma once

#include <iostream>
#include <exception>

using namespace std;

class invalid_matrix_size_exception : public exception {
public:
    const char* what() const noexcept override {
        return "invalid matrix size.";
    }
};