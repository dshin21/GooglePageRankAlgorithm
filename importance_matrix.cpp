#include "importance_matrix.hpp"

/*
 * importance_matrix constructor
 * @params connectivity_matrix& con_matrix, a connectivity matrix
 * @returns void
 */
importance_matrix::importance_matrix( connectivity_matrix& con_matrix )
        : matrix( importance_matrix::convert_to_importance( con_matrix ) ) {}

/*
 * Converts the connectivity_matrix to an importance_matrix
 * @params connectivity_matrix conn_matrix, connectivity matrix to be converted
 * @returns matrix
 */
matrix importance_matrix::convert_to_importance( connectivity_matrix conn_matrix ) {
    matrix imp_matrix( conn_matrix.get_matrix_row(), conn_matrix.get_matrix_column() );
    for ( int i = 0; i < conn_matrix.get_matrix_row(); ++i )
        for ( int j = 0; j < conn_matrix.get_matrix_column(); ++j ) {
            double sum{ matrix::sum_column( conn_matrix.get_column_as_vector( j ) ) };
            if ( sum != 0 ) imp_matrix.set_value( i, j, conn_matrix.get_value( i, j ) / sum );
        }
    return imp_matrix;
}
