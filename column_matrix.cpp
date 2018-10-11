#include "column_matrix.hpp"

/*
 * column_matrix constructor
 * @params  int size, the number of columns of the column matrix
 * @returns void
 */
column_matrix::column_matrix( int size )
        : matrix( size, 1 ) {
    for ( int i = 0; i < size; ++i ) matrix::set_value( i, 0, 1.0 );
}

/*
 * column_matrix constructor
 * @params transition_matrix& tran_matrix, transition matrix
 *          column_matrix& col_matrix, column matrix
 * @returns void
 */
column_matrix::column_matrix( transition_matrix& tran_matrix, column_matrix& col_matrix )
        : matrix( tran_matrix * col_matrix ) {};

/*
* column_matrix copy constructor
* @params  const column_matrix& col_matrix, the column matrix to be copied
* @returns void
*/
column_matrix::column_matrix( const column_matrix& col_matrix )
    : matrix( col_matrix ) {};

/*
 * Performs the Markov process on the transition matrix
 * @params transition_matrix tran_matrix, transition matrix to be used for the Markov process
 * @returns column_matrix
 */
column_matrix column_matrix::markov_process( transition_matrix tran_matrix ) {
    auto* cur = new column_matrix( tran_matrix, *this );
    auto* prev = new column_matrix( get_matrix_row() );
    while ( *cur != *prev ) {
        prev = cur;
        cur = new column_matrix( tran_matrix, *cur );
    }
    return *cur;
}

/*
 * Computes the rank of the column matrix
 * @params void
 * @returns void
 */
void column_matrix::scale_rank() {
    double sum = matrix::sum_column( get_column_as_vector( 0 ) );
    for ( int i = 0; i < get_matrix_row(); ++i ) set_value( i, 0, ( get_value( i, 0 ) / sum ) );
}
