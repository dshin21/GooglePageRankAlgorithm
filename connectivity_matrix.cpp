#include "connectivity_matrix.hpp"

connectivity_matrix::connectivity_matrix( double* array, int size )
        : matrix( array, size ) {
    for ( int i = 0; i < size; ++i )
        if ( ( array[ i ] - zero > matrix::tolerance && array[ i ] - one > matrix::tolerance ) || array[ i ] < zero )
            throw invalid_connectivity_matrix_exception();
}

connectivity_matrix connectivity_matrix::read_file( string file ) {
    ifstream connectivity_file( file );
    vector< double > temp;
    string element;

    while ( connectivity_file >> element ) {
        double digit;
        stringstream value( element );
        value >> digit;
        temp.push_back( digit );
    };
    connectivity_matrix conn_matrix( &temp[ 0 ], static_cast<int>(temp.size()) );
    return conn_matrix;
}
