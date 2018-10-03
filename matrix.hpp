//
// Created by danie on 2018-10-01.
//

#ifndef GOOGLEPAGERANKALGORITHM_MATRIX_HPP
#define GOOGLEPAGERANKALGORITHM_MATRIX_HPP


class matrix {
    matrix();

    matrix( int n );

    matrix( int r, int c );

    matrix( double doublearr[], int size );

    ~matrix();

    void set_value(int r, int c, double newValue);

    double get_value(int r, int c);

    void clear();

private:
    double *MATRIX;
    int row;
    int col;

};


#endif //GOOGLEPAGERANKALGORITHM_MATRIX_HPP

//TODO: add README.md

//Notes:
//matrix stores doubles