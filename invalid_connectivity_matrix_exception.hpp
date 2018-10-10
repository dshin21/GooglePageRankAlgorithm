#pragma once

#include <exception>
#include <iostream>

class invalid_connectivity_matrix_exception : public std::exception {
public:
    const char* what() const noexcept override {
        return "Not a valid Connectivity Matrix!";
    }
};