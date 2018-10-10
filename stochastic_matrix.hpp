#pragma once

#include "matrix.hpp"
#include "importance_matrix.hpp"

class stochastic_matrix : public matrix {
public:
    explicit stochastic_matrix( importance_matrix& imp_matrix );

    static matrix convert_to_stochastic( importance_matrix conn_matrix );
};


