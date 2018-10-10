#include "stochastic_matrix.hpp"

stochastic_matrix::stochastic_matrix( importance_matrix& imp_matrix )
        : matrix( stochastic_matrix::convert_to_stochastic( imp_matrix ) ) {}

matrix stochastic_matrix::convert_to_stochastic( importance_matrix imp_matrix ) {
    matrix sto_matrix( imp_matrix );
    for ( int i = 0; i < imp_matrix.get_matrix_row(); ++i )
        sto_matrix.set_value( i, imp_matrix.get_matrix_column() - 1, 1.0 / imp_matrix.get_matrix_column() );
    return sto_matrix;
}
