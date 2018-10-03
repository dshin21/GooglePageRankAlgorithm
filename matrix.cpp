//
// Created by danie on 2018-10-01.
//

#include "matrix.hpp"
#include <cmath>

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
    auto sqrt_size = static_cast<int>(sqrt( size ));
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

ostream &matrix::operator<<( ostream &os ) {
    for ( int i = 0; i < row; ++i ) {
        os << MATRIX[ i ];
        if ( i % row == 0 ) os << "\n";
    }
    return os;
}

bool matrix::operator==( const matrix &matrix ) {
    if ( row != matrix.row || col != matrix.col ) return false;

    for ( int i = 0; i < row; ++i )
        if ( abs( MATRIX[ i ] - matrix.MATRIX[ i ] ) > TOLERANCE )
            return false;
    return true;
}

bool matrix::operator!=( const matrix &matrix ) {
    if ( row != matrix.row || col != matrix.col ) return false;

    for ( int i = 0; i < row; ++i )
        if ( abs( MATRIX[ i ] - matrix.MATRIX[ i ] ) < TOLERANCE )
            return false;
    return true;
}

matrix &matrix::operator++() {
    for ( int i = 0; i < row * col; ++i )
        MATRIX[ i ]++;
    return reinterpret_cast<matrix &>(MATRIX);
}

const matrix matrix::operator++( int ) {
    for ( int i = 0; i < row * col; ++i )
        ++MATRIX[ i ];
    return reinterpret_cast<matrix &>(MATRIX);
}

matrix &matrix::operator--() {
    for ( int i = 0; i < row * col; ++i )
        MATRIX[ i ]--;
    return reinterpret_cast<matrix &>(MATRIX);
}

const matrix matrix::operator--( int ) {
    for ( int i = 0; i < row * col; ++i )
        --MATRIX[ i ];
    return reinterpret_cast<matrix &>(MATRIX);
}

matrix &matrix::operator=( matrix &matrix ) {
    std::swap( row, matrix.row );
    std::swap( col, matrix.col );
    std::swap( MATRIX, matrix.MATRIX );
    return *this;
}

matrix matrix::operator+( matrix &other_matrix ) {
    if ( row != other_matrix.row || col != other_matrix.col ) throw; //TODO: implement an exception
    matrix sum_matrix( row, col );
    for ( int i = 0; i < row; ++i )
        sum_matrix.MATRIX[ i ] += MATRIX[ i ] + other_matrix.MATRIX[ i ];
    return sum_matrix;
}

matrix &matrix::operator+=( matrix &other_matrix ) {
    if ( row != other_matrix.row || col != other_matrix.col ) throw; //TODO: implement an exception
    for ( int i = 0; i < row; ++i )
        MATRIX[ i ] += other_matrix.MATRIX[ i ];
    return reinterpret_cast<matrix &>(MATRIX);
}

matrix matrix::operator-( matrix &other_matrix ) {
    if ( row != other_matrix.row || col != other_matrix.col ) throw; //TODO: implement an exception
    matrix diff_matrix( row, col );
    for ( int i = 0; i < row; ++i )
        diff_matrix.MATRIX[ i ] -= MATRIX[ i ] + other_matrix.MATRIX[ i ];
    return diff_matrix;
}

matrix &matrix::operator-=( matrix &other_matrix ) {
    if ( row != other_matrix.row || col != other_matrix.col ) throw; //TODO: implement an exception
    for ( int i = 0; i < row; ++i )
        MATRIX[ i ] -= other_matrix.MATRIX[ i ];
    return reinterpret_cast<matrix &>(MATRIX);
}

//TODO: ask if we need to account for multiplying by a constant
matrix matrix::operator*( matrix &other_matrix ) {
    if ( col != other_matrix.row ) throw; //TODO: implement an exception
    matrix prod_matrix( row, col );
    //TODO: matrix mult. logic
    return prod_matrix;
}

//TODO: ask if we need to account for multiplying by a constant
matrix &matrix::operator*=( matrix &other_matrix ) {
    return <#initializer#>;
}
