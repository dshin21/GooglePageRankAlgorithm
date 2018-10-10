#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

class matrix {
private:
    int matrix_row;

    int matrix_column;

    double* the_matrix;

public:
    static constexpr double tolerance = 0.00001;

    matrix();

    explicit matrix( int n );

    matrix( int row, int column );

    matrix( double array[], int size );

    matrix( const matrix& matrix );

    ~matrix();

    void set_value( int row, int column, double value );

    const double& get_value( int row, int column ) const;

    void clear();

    static double sum_column( vector< double > column );

    friend ostream& operator<<( ostream& os, matrix& matrix );

    friend bool operator==( matrix& first, matrix& second );

    friend bool operator!=( matrix& first, matrix& second );

    matrix& operator++();

    const matrix operator++( int );

    matrix& operator--();

    const matrix operator--( int );

    matrix& operator=( matrix matrix );

    matrix& operator+=( const matrix& rhs );

    friend matrix operator+( matrix& lhs, const matrix& rhs );

    matrix& operator-=( const matrix& rhs );

    friend matrix operator-( matrix& lhs, const matrix& rhs );

    matrix& operator*=( const matrix& rhs );

    friend matrix operator*( matrix& lhs, matrix& rhs );

    matrix& operator*=( double );

    friend matrix operator*( double lhs, matrix& rhs );

    static double matrix_multiplication( vector< double > first_vector, vector< double > sec_vector );

    const int get_matrix_row();

    const int get_matrix_column();

    vector< double > get_row_as_vector( int row_index );

    vector< double > get_column_as_vector( int col_index );
};


