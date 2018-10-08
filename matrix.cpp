//
// Created by danie on 2018-10-01.
//

#include "matrix.hpp"


matrix::matrix() : row( 1 ), col( 1 ), MATRIX( new double[row * col] ) {
    clear();
}

matrix::matrix( int n ) : row( n ), col( n ) {
    if ( n < 0 || n == 0 ) throw;  //TODO: implement an exception
    MATRIX = new double[n * n];
    clear();
}

matrix::matrix( int r, int c ) : row( r ), col( c ) {
    if (( r < 0 || r == 0 ) && ( c < 0 || c == 0 )) throw;  //TODO: implement an exception
    MATRIX = new double[r * c];
    clear();
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

ostream &operator<<( ostream &os, const matrix &matrix ) {
    for ( int i = 0; i < matrix.row; ++i ) {
        for ( int j = 0; j < matrix.col; ++j )
            cout << matrix.get_value( i, j );
        cout << "\n";
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
    return !operator==( first, second );
}

matrix &matrix::operator++() {
    for ( int i = 0; i < row; ++i )
        for ( int j = 0; j < col; ++j )
            set_value( i, j, get_value( i, j ) + 1 );
    return *this;
}

const matrix matrix::operator++( int ) {
    matrix temp( *this );
    operator++();
    return temp;
}

matrix &matrix::operator--() {
    for ( int i = 0; i < row; ++i )
        for ( int j = 0; j < col; ++j )
            set_value( i, j, get_value( i, j ) - 1 );
    return *this;
}

const matrix matrix::operator--( int ) {
    matrix temp( *this );
    operator--();
    return temp;
}

matrix &matrix::operator=( matrix &matrix ) {
    using std::swap;
    swap( row, matrix.row );
    swap( col, matrix.col );
    swap( MATRIX, matrix.MATRIX );
    return *this;
}

matrix &matrix::operator+=( const matrix &rhs ) {
    if ( row != rhs.row || col != rhs.col ) throw; //TODO: implement an exception

    for ( int i = 0; i < row; ++i )
        for ( int j = 0; j < col; ++j )
            MATRIX[ i * row + j ] += rhs.get_value( i, j );
    return *this;
}

matrix operator+( matrix &lhs, const matrix &rhs ) {
    lhs += rhs;
    return lhs;
}

matrix &matrix::operator-=( const matrix &rhs ) {
    if ( row != rhs.row || col != rhs.col ) throw; //TODO: implement an exception

    for ( int i = 0; i < row; ++i )
        for ( int j = 0; j < col; ++j )
            MATRIX[ i * row + j ] -= rhs.get_value( i, j );
    return *this;
}

matrix operator-( matrix &lhs, const matrix &rhs ) {
    lhs -= rhs;
    return lhs;
}

matrix &matrix::operator*=( const matrix &rhs ) {
    if ( row != rhs.row || col != rhs.col ) throw; //TODO: implement an exception

    for ( int i = 0; i < row; ++i )
        for ( int j = 0; j < col; ++j )
            MATRIX[ i * row + j ] *= rhs.get_value( i, j );
    return *this;
}


matrix operator*( matrix &lhs, const matrix &rhs ) {
    lhs *= rhs;
    return lhs;
}

matrix operator*( matrix &lhs, double value ) {
    for ( int i = 0; i < lhs.row; ++i )
        for ( int j = 0; j < lhs.col; ++j )
            lhs.MATRIX[ i * lhs.row + j ] *= value;
    return lhs;
}


