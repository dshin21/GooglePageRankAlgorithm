/*
* Created by Daniel Shin on 2018-10-07.
*/

#pragma once

#include "stochastic_matrix.hpp"

stochastic_matrix::stochastic_matrix( importance_matrix &imp_matrix )
        : importance_matrix( stochastic_matrix::convert_to_stochastic( imp_matrix )) {}

importance_matrix stochastic_matrix::convert_to_stochastic( importance_matrix imp_matrix ) {
    importance_matrix temp( imp_matrix );
    for ( int i = 0; i < imp_matrix.row; ++i ) {
        temp.set_value( i, imp_matrix.col - 1, 1.0 / imp_matrix.row );
    }
    return temp;
}
