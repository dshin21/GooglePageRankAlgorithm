#pragma once

#include <iostream>
#include <exception>


/*
  * exception for when a received matrix size is not a valid size
  * @params void
  * @returns const char*, exception message
  */
class invalid_matrix_size_exception : public std::exception {
public:
    const char* what() const noexcept override {
        return "invalid matrix size.";
    }
};