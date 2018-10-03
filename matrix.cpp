//
// Created by danie on 2018-10-01.
//

#include "matrix.hpp"
#include <math.h>

matrix::matrix() : row( 1 ), col( 1 ), MATRIX( new double[row * col] ) {
    MATRIX[ 0 ] = 0.0;
}

matrix::matrix( int n ) : row( n ), col( n ) {
    if ( n < 0 || n == 0 ) throw;  //TODO: implement an exception

    MATRIX = new double[n * n];
    for ( int i = 0; i < n * n; ++i ) MATRIX[ i ] = 0.0;
}

matrix::matrix( int r, int c ) : row( r ), col( c ) {
    if (( r < 0 || r == 0 ) && ( c < 0 || c == 0 )) throw;  //TODO: implement an exception

    MATRIX = new double[r * c];
    for ( int i = 0; i < r * c; ++i ) MATRIX[ i ] = 0.0;
}

matrix::matrix( double *double_arr, int size ) {
    int sqrt_size = static_cast<int>(sqrt( size ));
    if ( pow( size, 2 ) != sqrt_size ) throw; //TODO: implement an exception

    row = sqrt_size;
    col = sqrt_size;
    MATRIX = new double[size];

    for ( int i = 0; i < size; ++i ) MATRIX[ i ] = double_arr[ i ];
}

matrix::~matrix() {
    delete[] MATRIX;
}

void matrix::set_value( int r, int c, double newValue ) {
    if ( r < 0 || c < 0 || ( r * c > row * col )) throw; //TODO: implement an exception
    MATRIX[ ( row * r ) + c ] = newValue;
}

double matrix::get_value( int r, int c ) const {
    if ( r < 0 || c < 0 || ( r * c > row * col )) throw;
    return MATRIX[ ( row * r ) + c ];
}

void matrix::clear() {
    for ( int i = 0; i < row * col; ++i )
        MATRIX[ i ] = 0.0;
}

ostream &operator<<( ostream &os, const matrix &matrix ) {
    for ( int r = 0; r < matrix.row; ++r ) {
        for ( int c = 0; c < matrix.col; ++c )
            os << matrix.get_value( r, c );
        os << "\n";
    }
    return os;
}

bool operator==( const matrix &first, const matrix &second ) {
    if ( first.row != second.row || first.col != second.col ) return false;

    for ( int i = 0; i < first.row; ++i )
        for ( int j = 0; j < first.col; ++j )
            if ( abs( first.get_value( i, j ) - second.get_value( i, j )) > matrix::TOLERANCE )
                return false;
    return true;
}

bool operator!=( const matrix &first, const matrix &second ) {
    if ( first.row != second.row || first.col != second.col ) return false;

    for ( int i = 0; i < first.row; ++i )
        for ( int j = 0; j < first.col; ++j )
            if ( abs( first.get_value( i, j ) - second.get_value( i, j )) <= matrix::TOLERANCE )
                return false;
    return true;
}




