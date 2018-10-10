#include "matrix.hpp"

//done
matrix::matrix()
        : matrix_row( 1 ),
          matrix_column( 1 ),
          the_matrix( new double[matrix_row * matrix_column] ) {
    clear();
}

//done
matrix::matrix( int n )
        : matrix_row( n ),
          matrix_column( n ),
          the_matrix( new double[n * n] ) {
    if ( n <= 0 ) throw invalid_matrix_size_exception();
    clear();
}

//done
matrix::matrix( int row, int column )
        : matrix_row( row ),
          matrix_column( column ) {
    if ( row <= 0 || column <= 0 ) throw invalid_matrix_size_exception();
    the_matrix = new double[row * column];
    clear();
}

// done
matrix::matrix( double array[], int size ) {
    auto sqrt_size = static_cast<int>(sqrt( size ));
    if ( pow( sqrt_size, 2 ) != size ) throw invalid_matrix_size_exception();
    matrix_row = sqrt_size;
    matrix_column = sqrt_size;
    the_matrix = new double[size];
    for ( int i = 0; i < size; ++i ) the_matrix[ i ] = array[ i ];
}

//done
matrix::matrix( const matrix& matrix )
        : matrix_row( matrix.matrix_row ),
          matrix_column( matrix.matrix_column ),
          the_matrix( new double[matrix_row * matrix_column] ) {
    for ( int i = 0; i < matrix_row * matrix_column; ++i )the_matrix[ i ] = matrix.the_matrix[ i ];
}

//done
matrix::~matrix() {
    delete[] the_matrix;
}

//done
void matrix::set_value( int row, int column, double value ) {
    if ( row < 0 || column < 0 || row * column > matrix_row * matrix_column ) throw invalid_matrix_size_exception();
    the_matrix[ ( matrix_column * row ) + column ] = value;
}

//done
const double& matrix::get_value( int row, int column ) const {
    if ( row < 0 || column < 0 || row * column > matrix_row * matrix_column ) throw invalid_matrix_size_exception();
    return the_matrix[ ( matrix_column * row ) + column ];
}

// done
void matrix::clear() {
    for ( int i = 0; i < matrix_row * matrix_column; ++i ) the_matrix[ i ] = 0.0;
}

// done
ostream& operator<<( ostream& os, matrix& matrix ) {
    for ( int i = 0; i < matrix.matrix_row; ++i ) {
        for ( int j = 0; j < matrix.matrix_column; ++j )
            os << setw( 15 ) << left << matrix.get_value( i, j );
        os << endl;
    }
    return os;
}

// done
bool operator==( matrix& first, matrix& second ) {
    if ( first.get_matrix_row() != second.get_matrix_row() ||
         first.get_matrix_column() != second.get_matrix_column() )
        return false;
    for ( int i = 0; i < first.get_matrix_row(); ++i )
        for ( int j = 0; j < first.get_matrix_column(); ++j ) {
            double temp = abs( first.get_value( i, j ) - second.get_value( i, j ) );
            if ( temp > matrix::tolerance ) return false;
        }
    return true;
}

// done
bool operator!=( matrix& first, matrix& second ) {
    return !operator==( first, second );
}

// done
matrix& matrix::operator++() {
    for ( int i = 0; i < get_matrix_row(); ++i )
        for ( int j = 0; j < get_matrix_column(); ++j )
            set_value( i, j, get_value( i, j ) + 1 );
    return *this;
}

// done
const matrix matrix::operator++( int ) {
    matrix temp( *this );
    operator++();
    return temp;
}

// done
matrix& matrix::operator--() {
    for ( int i = 0; i < get_matrix_row(); ++i )
        for ( int j = 0; j < get_matrix_column(); ++j )
            set_value( i, j, get_value( i, j ) - 1 );
    return *this;
}

// done
const matrix matrix::operator--( int ) {
    matrix temp( *this );
    operator--();
    return temp;
}

// done
matrix& matrix::operator=( matrix matrix ) {
    swap( matrix_row, matrix.matrix_row );
    swap( matrix_column, matrix.matrix_column );
    swap( the_matrix, matrix.the_matrix );
    return *this;
}

// done
matrix& matrix::operator+=( const matrix& rhs ) {
    if ( matrix_row != rhs.matrix_row || matrix_column != rhs.matrix_column ) throw invalid_matrix_size_exception();
    for ( int i = 0; i < matrix_row; ++i )
        for ( int j = 0; j < matrix_column; ++j )
            the_matrix[ i * matrix_row + j ] += rhs.get_value( i, j );
    return *this;
}

// done
matrix operator+( matrix& lhs, const matrix& rhs ) {
    lhs += rhs;
    return lhs;
}

// done
matrix& matrix::operator-=( const matrix& rhs ) {
    if ( matrix_row != rhs.matrix_row || matrix_column != rhs.matrix_column ) throw invalid_matrix_size_exception();
    for ( int i = 0; i < matrix_row; ++i )
        for ( int j = 0; j < matrix_column; ++j )
            the_matrix[ i * matrix_row + j ] -= rhs.get_value( i, j );
    return *this;
}

// done
matrix operator-( matrix& lhs, const matrix& rhs ) {
    lhs -= rhs;
    return lhs;
}

//done
matrix& matrix::operator*=( const matrix& rhs ) {
    if ( matrix_row != rhs.matrix_row || matrix_column != rhs.matrix_column ) throw invalid_matrix_size_exception();
    for ( int i = 0; i < matrix_row; ++i )
        for ( int j = 0; j < matrix_column; ++j )
            the_matrix[ i * matrix_row + j ] *= rhs.get_value( i, j );
    return *this;
}

//done
matrix operator*( matrix& lhs, matrix& rhs ) {
    if ( lhs.matrix_column != rhs.matrix_row ) throw invalid_matrix_size_exception();
    matrix temp( lhs.matrix_row, rhs.matrix_column );
    for ( int i = 0; i < lhs.matrix_row; ++i )
        for ( int j = 0; j < rhs.matrix_column; ++j )
            temp.set_value( i, j, matrix::matrix_multiplication( lhs.get_row_as_vector( i ),
                                                                 rhs.get_column_as_vector( j ) ) );
    return temp;
}

//done
matrix& matrix::operator*=( const double constant ) {
    for ( int i = 0; i < matrix_row; ++i )
        for ( int j = 0; j < matrix_column; ++j )
            the_matrix[ i * matrix_row + j ] *= constant;
    return *this;
}

//done
matrix operator*( double value, matrix& lhs ) {
    lhs *= value;
    return lhs;
}

//done
vector< double > matrix::get_row_as_vector( int row_index ) {
    vector< double > row_vector;
    for ( int i = 0; i < matrix_column; ++i ) row_vector.push_back( get_value( row_index, i ) );
    return row_vector;
}

//done
vector< double > matrix::get_column_as_vector( int col_index ) {
    vector< double > column_vector;
    for ( int i = 0; i < matrix_row; ++i ) column_vector.push_back( get_value( i, col_index ) );
    return column_vector;
}

//done
double matrix::matrix_multiplication( vector< double > rhs, vector< double > lhs ) {
    double sum = 0;
    if ( rhs.size() != lhs.size() ) throw invalid_vector_size_exception();
    for ( int i = 0; i < rhs.size(); i++ ) sum += rhs[ i ] * lhs[ i ];
    return sum;
}

//done
double matrix::sum_column( vector< double > column_vector ) {
    double sum = 0;
    for ( double i : column_vector ) sum += i;
    return sum;
}

// done
const int matrix::get_matrix_row() {
    return matrix_row;
}

// done
const int matrix::get_matrix_column() {
    return matrix_column;
}


