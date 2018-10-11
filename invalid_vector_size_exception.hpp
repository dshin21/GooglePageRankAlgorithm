#pragma once

#include <iostream>
#include <exception>

using namespace std;

/*
  * exception for when a vector size is not a valid size
  * @params void
  * @returns const char*, exception message
  */class invalid_vector_size_exception : public exception {
public:
    const char* what() const noexcept override {
        return "invalid vector size.";
    }
};