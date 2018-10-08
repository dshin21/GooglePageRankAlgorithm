//
// Created by danie on 2018-10-01.
//

#ifndef GOOGLEPAGERANKALGORITHM_MATRIX_HPP
#define GOOGLEPAGERANKALGORITHM_MATRIX_HPP

#include <iomanip>
#include <cmath>
#include <iostream>

using namespace std;

class matrix {
public:
    double *MATRIX;
    int row, col;
    static constexpr double TOLERANCE = 0.001;

    matrix();

    matrix( int );

    matrix( int, int );

    matrix( double *, int );

    ~matrix();

    void set_value( int, int, double );

    double get_value( int, int ) const;

    void clear();

    friend ostream &operator<<( ostream &, const matrix & );

    friend bool operator==( const matrix &, const matrix & );

    friend bool operator!=( const matrix &, const matrix & );

    matrix &operator++();

    const matrix operator++( int );

    matrix &operator--();

    const matrix operator--( int );

    matrix &operator=( matrix & );

    matrix &operator+=( const matrix & );

    friend matrix operator+( matrix &, const matrix & );

    matrix &operator-=( const matrix & );

    friend matrix operator-( matrix &, const matrix & );

    matrix &operator*=( const matrix & );

    friend matrix operator*( matrix &, const matrix & );

    friend matrix operator*( matrix &, double );

private:


};


#endif //GOOGLEPAGERANKALGORITHM_MATRIX_HPP

//TODO: add README.md
