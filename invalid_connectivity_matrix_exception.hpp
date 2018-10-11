#pragma once

#include <exception>
#include <iostream>

class invalid_connectivity_matrix_exception : public std::exception {
public:

    /*
     * exception for when a received matrix is not a valid connectivity matrix
     * @params void
     * @returns const char*, exception message
     */
    const char* what() const noexcept override {
        return "Not a valid Connectivity Matrix!";
    }
};