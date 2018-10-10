#include "importance_matrix.hpp"

importance_matrix::importance_matrix( connectivity_matrix& cm )
        : matrix( importance_matrix::convert_to_importance( cm ) ) {}

matrix importance_matrix::convert_to_importance( connectivity_matrix conn_matrix ) {
    matrix imp_matrix( conn_matrix.get_matrix_row(), conn_matrix.get_matrix_column() );
    for ( int i = 0; i < conn_matrix.get_matrix_row(); ++i )
        for ( int j = 0; j < conn_matrix.get_matrix_column(); ++j ) {
            double sum{ matrix::sum_column( conn_matrix.get_column_as_vector( j ) ) };
            if ( sum != 0 ) imp_matrix.set_value( i, j, conn_matrix.get_value( i, j ) / sum );
        }
    return imp_matrix;
}
