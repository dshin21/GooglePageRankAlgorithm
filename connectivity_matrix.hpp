//
// Created by Daniel Shin on 2018-10-07.
//

#pragma once

#include "matrix.hpp"
#include "invalid_connectivity_matrix_exception.hpp"

class connectivity_matrix : public matrix {
    static constexpr int zero = 0;
    static constexpr int one = 1;

    connectivity_matrix( double *, int );

    connectivity_matrix create_connectivity_matrix( std::string );
};

