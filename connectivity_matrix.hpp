#pragma once

#include "matrix.hpp"
#include "invalid_connectivity_matrix_exception.hpp"
#include <vector>
#include <fstream>

class connectivity_matrix : public matrix {
public:
    static constexpr int zero = 0;

    static constexpr int one = 1;

    connectivity_matrix( double* matrix, int size);

    static connectivity_matrix read_file( string fileName);
};

