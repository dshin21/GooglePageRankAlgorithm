//
// Created by danie on 2018-10-01.
//

#ifndef GOOGLEPAGERANKALGORITHM_MATRIX_HPP
#define GOOGLEPAGERANKALGORITHM_MATRIX_HPP

#include <iomanip>

using namespace std;

class matrix {
public:
    static constexpr double TOLERANCE = 0.001;

    matrix();

    matrix( int n );

    matrix( int r, int c );

    matrix( double double_arr[], int size );

    ~matrix();

    void set_value( int r, int c, double newValue );

    double get_value( int r, int c ) const;

    void clear();

    friend ostream &operator<<( ostream &os, const matrix &matrix );

    friend bool operator==( const matrix &first, const matrix &second );

    friend bool operator!=( const matrix &first, const matrix &second );


private:
    double *MATRIX;
    int row;
    int col;


};


#endif //GOOGLEPAGERANKALGORITHM_MATRIX_HPP

//TODO: add README.md
