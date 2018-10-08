//
// Created by danie on 2018-10-07.
//

#include <vector>
#include <fstream>
#include "connectivity_matrix.hpp"

connectivity_matrix::connectivity_matrix( double *array, int size ) : matrix( array, size ) {
    for ( int i = 0; i < size; ++i )
        if (( array[ i ] - zero > matrix::tolerance && array[ i ] - one > matrix::tolerance ) || array[ i ] < zero )
            throw invalid_connectivity_matrix_exception();
}

connectivity_matrix connectivity_matrix::create_connectivity_matrix( const std::string file_path ) {
    vector< double > matrix;
    string text;

    while ( ifstream{ file_path } >> text ) {
        double digit;
        stringstream to_string{ text };
        to_string >> digit;
        matrix.push_back( digit );
    }

    return connectivity_matrix( &matrix[ 0 ], static_cast<int>(matrix.size()));
}
