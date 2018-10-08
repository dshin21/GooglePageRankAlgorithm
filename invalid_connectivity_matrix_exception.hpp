/*
* Created by Daniel Shin on 2018-10-07.
*/

#pragma once

#include <exception>
#include <iostream>

class invalid_connectivity_matrix_exception : public std::exception {
public:
    const char *what() const throw() {
        return "Not a valid Connectivity Matrix!";
    }
};