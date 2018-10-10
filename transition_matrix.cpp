#include "transition_matrix.hpp"

transition_matrix::transition_matrix( stochastic_matrix sto_matrix, q_matrix q_matrix )
        : matrix( transition_matrix::covert_to_transition( std::move( sto_matrix ), std::move( q_matrix ) ) ) {}

matrix transition_matrix::covert_to_transition( stochastic_matrix sto_matrix, q_matrix q_matrix ) {
    matrix lhs{ transition_matrix::p * sto_matrix };
    matrix rhs{ ( 1.0 - transition_matrix::p ) * q_matrix };
    return lhs + rhs;
}

