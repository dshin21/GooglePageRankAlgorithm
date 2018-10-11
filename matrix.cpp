#include "matrix.hpp"

/*
 * matrix constructor
 * @params void
 * @returns void
 */
matrix::matrix()
        : matrix_row( 1 ),
          matrix_column( 1 ),
          the_matrix( new double[matrix_row * matrix_column] ) {
    clear();
}

/*
 * matrix constructor
 * @params int n, size of the matrix
 * @returns void
 */
matrix::matrix( int n )
        : matrix_row( n ),
          matrix_column( n ),
          the_matrix( new double[n * n] ) {
    if ( n <= 0 )
        throw invalid_matrix_size_exception();
    clear();
}

/*
 * matrix constructor
 * @params int row, size of the row of the matrix
 *          int column, size of the column of the matrix
 * @returns void
 */
matrix::matrix( int row, int column )
        : matrix_row( row ),
          matrix_column( column ) {
    if ( row <= 0 || column <= 0 )
        throw invalid_matrix_size_exception();
    the_matrix = new double[row * column];
    clear();
}

/*
 * matrix constructor
 * @params double array[], array of doubles to be made into a matrix
 *          int size, size of the matrix
 * @returns void
 */
matrix::matrix( double array[], int size ) {
    auto sqrt_size = static_cast<int>(sqrt( size ));
    if ( pow( sqrt_size, 2 ) != size )
        throw invalid_matrix_size_exception();
    matrix_row = sqrt_size;
    matrix_column = sqrt_size;
    the_matrix = new double[size];
    for ( int i = 0; i < size; ++i )
        the_matrix[ i ] = array[ i ];
}

/*
 * matrix copy constructor
 * @params const matrix& matrix, matrix to be copied from
 * @returns void
 */
matrix::matrix( const matrix& matrix )
        : matrix_row( matrix.matrix_row ),
          matrix_column( matrix.matrix_column ),
          the_matrix( new double[matrix_row * matrix_column] ) {
    for ( int i = 0; i < matrix_row * matrix_column; ++i )
        the_matrix[ i ] = matrix.the_matrix[ i ];
}

/*
 * matrix destructor
 * @params void
 * @returns void
 */
matrix::~matrix() {
    delete[] the_matrix;
}

/*
 * Sets the value of the matrix
 * @params int row, specifies the row of the new value
 *         int column, specifies the column of the new value
 *         double value, the new value to be set
 * @returns void
 */
void matrix::set_value( int row, int column, double value ) {
    if ( row < 0 || column < 0 || row * column > matrix_row * matrix_column )
        throw invalid_matrix_size_exception();
    the_matrix[ ( matrix_column * row ) + column ] = value;
}

/*
 * Gets the value of the matrix
 * @params int row, the row of the value of the matrix to be retrieved
 *         int column, the column of the value of the matrix to be retrieved
 * @returns const double&, returned value at the specified row and column
 */
const double& matrix::get_value( int row, int column ) const {
    if ( row < 0 || column < 0 || row * column > matrix_row * matrix_column )
        throw invalid_matrix_size_exception();
    return the_matrix[ ( matrix_column * row ) + column ];
}

/*
 * Sets all the values of the matrix to 0.0
 * @params void
 * @returns void
 */
void matrix::clear() {
    for ( int i = 0; i < matrix_row * matrix_column; ++i )
        the_matrix[ i ] = 0.0;
}

/*
 * Prints the matrix contents
 * @params ostream& os, the output stream
 *         matrix& matrix, the matrix to be printed
 * @returns ostream&, the reference to the output stream
 */
ostream& operator<<( ostream& os, matrix& matrix ) {
    for ( int i = 0; i < matrix.matrix_row; ++i ) {
        for ( int j = 0; j < matrix.matrix_column; ++j )
            os << setw( 15 ) << left << matrix.get_value( i, j );
        os << endl;
    }
    return os;
}

/*
 * Checks the equality of the two matrices
 * @params matrix& lhs, the left operand matrix
 *         matrix& rhs, the right operand matrix
 * @returns true if the two matrices are equal; false otherwise
 */
bool operator==( matrix& lhs, matrix& rhs ) {
    if ( lhs.get_matrix_row() != rhs.get_matrix_row() ||
            lhs.get_matrix_column() != rhs.get_matrix_column() )
        return false;
    for ( int i = 0; i < lhs.get_matrix_row(); ++i )
        for ( int j = 0; j < lhs.get_matrix_column(); ++j ) {
            double temp = abs( lhs.get_value( i, j ) - rhs.get_value( i, j ) );
            if ( temp > matrix::tolerance ) return false;
        }
    return true;
}

/*
 * checks the inequality of the two matricies
 * @params matrix& lhs, the left operand matrix
 *         matrix& rhs, the right operand matrix
 * @returns true if the two matrices are not equal; false otherwise
 */
bool operator!=( matrix& lhs, matrix& rhs ) {
    return !operator==( lhs, rhs );
}

/*
 * Prefix increments all the values of the matrix
 * @params void
 * @returns matrix&, incremeted matrix
 */
matrix& matrix::operator++() {
    for ( int i = 0; i < get_matrix_row(); ++i )
        for ( int j = 0; j < get_matrix_column(); ++j )
            set_value( i, j, get_value( i, j ) + 1 );
    return *this;
}

/*
 * Postfix increments all the values of the matrix
 * @params int, signifies that it is a postfix increment
 * @returns const matrix, incremented matrix
 */
const matrix matrix::operator++( int ) {
    matrix temp( *this );
    operator++();
    return temp;
}

/*
 * Prefix increments all the values of the matrix
 * @params void
 * @returns matrix&, incremeted matrix
 */
matrix& matrix::operator--() {
    for ( int i = 0; i < get_matrix_row(); ++i )
        for ( int j = 0; j < get_matrix_column(); ++j )
            set_value( i, j, get_value( i, j ) - 1 );
    return *this;
}

/*
 * Postfix decrements all the values of the matrix
 * @params int, signifies that it is a postfix decrement
 * @returns const matrix, decremented matrix
 */
const matrix matrix::operator--( int ) {
    matrix temp( *this );
    operator--();
    return temp;
}

/*
 * Assigns the matrix to the left operand matrix
 * @params matrix matrix, matrix to be assigned
 * @returns matrix&, reference to the matrix assigned
 */
matrix& matrix::operator=( matrix matrix ) {
    swap( matrix_row, matrix.matrix_row );
    swap( matrix_column, matrix.matrix_column );
    swap( the_matrix, matrix.the_matrix );
    return *this;
}

/*
 * Adds and assigns the right operand matrix to the left operand matrix
 * @params const matrix& rhs, matrix to be added
 * @returns matrix&, reference to the matrix added
 */
matrix& matrix::operator+=( const matrix& rhs ) {
    if ( matrix_row != rhs.matrix_row || matrix_column != rhs.matrix_column )
        throw invalid_matrix_size_exception();
    for ( int i = 0; i < matrix_row; ++i )
        for ( int j = 0; j < matrix_column; ++j )
            the_matrix[ i * matrix_row + j ] += rhs.get_value( i, j );
    return *this;
}

/*
 * Performs matrix addition
 * @params matrix& lhs, left operand of the matrix addition
 *         const matrix& rhs, right operand of the matrix addition
 * @returns sum of the two matrices
 */
matrix operator+( matrix& lhs, const matrix& rhs ) {
    lhs += rhs;
    return lhs;
}

/*
 * Subtracts and assigns the right operand matrix to the left operand matrix
 * @params const matrix& rhs, matrix to be subtracted
 * @returns matrix&, reference to the matrix subtracted
 */
matrix& matrix::operator-=( const matrix& rhs ) {
    if ( matrix_row != rhs.matrix_row || matrix_column != rhs.matrix_column )
        throw invalid_matrix_size_exception();
    for ( int i = 0; i < matrix_row; ++i )
        for ( int j = 0; j < matrix_column; ++j )
            the_matrix[ i * matrix_row + j ] -= rhs.get_value( i, j );
    return *this;
}

/*
 * Performs matrix subtraction
 * @params matrix& lhs, left operand of the matrix subtraction
 *         const matrix& rhs, right operand of the matrix subtraction
 * @returns difference of the two matrices
 */
matrix operator-( matrix& lhs, const matrix& rhs ) {
    lhs -= rhs;
    return lhs;
}

/*
 * performs matrix multiplication and assigns it to the left operand
 * @params const matrix& rhs, matrix to be multiplied
 * @returns matrix&, reference to the product matrix
 */
matrix& matrix::operator*=( const matrix& rhs ) {
    if ( matrix_row != rhs.matrix_row || matrix_column != rhs.matrix_column )
        throw invalid_matrix_size_exception();
    for ( int i = 0; i < matrix_row; ++i )
        for ( int j = 0; j < matrix_column; ++j )
            the_matrix[ i * matrix_row + j ] *= rhs.get_value( i, j );
    return *this;
}

/*
 * Performs matrix multiplication
 * @params matrix& lhs, left operand of the matrix multiplication
 *         const matrix& rhs, right operand of the matrix multiplication
 * @returns product of the two matrices
 */
matrix operator*( matrix& lhs, matrix& rhs ) {
    if ( lhs.matrix_column != rhs.matrix_row )
        throw invalid_matrix_size_exception();
    matrix temp( lhs.matrix_row, rhs.matrix_column );
    for ( int i = 0; i < lhs.matrix_row; ++i )
        for ( int j = 0; j < rhs.matrix_column; ++j )
            temp.set_value( i, j, matrix::matrix_multiplication( lhs.get_row_as_vector( i ),
                                                                 rhs.get_column_as_vector( j ) ) );
    return temp;
}

/*
 * Performs matrix multiplication by a constant and assigns it to the left operand
 * @params const double constant, constant to be multiplied
 * @returns matrix&, reference to the product matrix
 */
matrix& matrix::operator*=( const double constant ) {
    for ( int i = 0; i < matrix_row; ++i )
        for ( int j = 0; j < matrix_column; ++j )
            the_matrix[ i * matrix_row + j ] *= constant;
    return *this;
}

/*
 * Performs matrix multiplication by a constant
 * @params double value, constant value to be multiplied
 *         matrix& lhs, left operand of the matrix constant multiplication
 * @returns product of the matrix multiplication by a constant
 */
matrix operator*( double value, matrix& lhs ) {
    lhs *= value;
    return lhs;
}

/*
 * Returns the row of the matrix as a vector
 * @params int row_index, index of the row to be retrieved
 * @returns vector<double>, vector of doubles containing the row values
 */
vector< double > matrix::get_row_as_vector( int row_index ) {
    vector< double > row_vector;
    for ( int i = 0; i < matrix_column; ++i )
        row_vector.push_back( get_value( row_index, i ) );
    return row_vector;
}

/*
 * Returns the column of the matrix as a vector
 * @params int col_index, index of the column to be retrieved
 * @returns vector<double>, vector of doubles containing the column values
 */
vector< double > matrix::get_column_as_vector( int col_index ) {
    vector< double > column_vector;
    for ( int i = 0; i < matrix_row; ++i )
        column_vector.push_back( get_value( i, col_index ) );
    return column_vector;
}

/*
 * Computes the product (dot product) of the matrices
 * @params vector<double> rhs, right operand of the multiplication
 *         vector<double> lhs, left operand of the multiplication
 * @returns double, product of the multiplication
 */
double matrix::matrix_multiplication( vector< double > rhs, vector< double > lhs ) {
    double sum = 0;
    if ( rhs.size() != lhs.size() )
        throw invalid_vector_size_exception();
    for ( int i = 0; i < rhs.size(); i++ )
        sum += rhs[ i ] * lhs[ i ];
    return sum;
}

/*
 * Computes the sum of the matrices
 * @params vector< double > column_vector, column values to be summed
 * @returns
 */
double matrix::sum_column( vector< double > column_vector ) {
    double sum = 0;
    for ( double i : column_vector )
        sum += i;
    return sum;
}

/*
 * Returns the size of the row of the matrix
 * @params void
 * @returns const int, number of rows of the matrix
 */
const int matrix::get_matrix_row() {
    return matrix_row;
}

/*
 * Returns the size of the column of the matrix
 * @params void
 * @returns const int, number of columns of the matrix
 */
const int matrix::get_matrix_column() {
    return matrix_column;
}


