/*
* Created by Daniel Shin on 2018-10-07.
*/

#pragma once

#include "importance_matrix.hpp"

importance_matrix::importance_matrix( connectivity_matrix &con_matrix )
        : matrix( importance_matrix::convert_to_importance( con_matrix )) {}

matrix importance_matrix::convert_to_importance( connectivity_matrix con_matrix ) {
    matrix temp( con_matrix.row, con_matrix.col );
    for ( int i = 0; i < con_matrix.row; ++i )
        for ( int j = 0; j < con_matrix.col - 1; ++j ) {
            temp.set_value( i, j, con_matrix.get_value( i, j ) / sum_col( con_matrix, j ));
        }
    return temp;
}

double importance_matrix::sum_col( const matrix con_matrix, int col ) {
    double sum{ 0.0 };
    for ( int i = 0; i < con_matrix.row; ++i )
        sum += con_matrix.get_value( i, col );
    return sum;
}

