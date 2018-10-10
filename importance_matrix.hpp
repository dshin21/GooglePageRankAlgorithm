#pragma once

#include "matrix.hpp"
#include "connectivity_matrix.hpp"

class importance_matrix : public matrix {
public:
    explicit importance_matrix( connectivity_matrix& conn_matrix );

    static matrix convert_to_importance( connectivity_matrix conn_matrix );
};


