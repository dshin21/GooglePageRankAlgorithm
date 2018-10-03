//
// Created by danie on 2018-10-01.
//

#ifndef GOOGLEPAGERANKALGORITHM_MATRIX_HPP
#define GOOGLEPAGERANKALGORITHM_MATRIX_HPP

#include <iomanip>

using namespace std;

class matrix {
public:
    double *MATRIX;
    int row;
    int col;
    static constexpr double TOLERANCE = 0.001;

    matrix();

    matrix( int n );

    matrix( int r, int c );

    matrix( double double_arr[], int size );

    ~matrix();

    void set_value( int r, int c, double newValue );

    double get_value( int r, int c ) const;

    void clear();

    ostream &operator<<( ostream &os );

    bool operator==( const matrix &matrix );

    bool operator!=( const matrix &matrix );

    matrix &operator++();

    const matrix operator++( int );

    matrix &operator--();

    const matrix operator--( int );

    matrix &operator=( matrix &matrix );

    matrix operator+(matrix &other_matrix );

    matrix &operator+=( matrix &other_matrix );

    matrix operator-(matrix &other_matrix );

    matrix &operator-=( matrix &other_matrix );

    matrix operator*(matrix &other_matrix );

    matrix &operator*=( matrix &other_matrix );

private:


};


#endif //GOOGLEPAGERANKALGORITHM_MATRIX_HPP

//TODO: add README.md
