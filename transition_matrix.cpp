#include "transition_matrix.hpp"

/*
 * transition_matrix constructor
 * @params stochastic_matrix sto_matrix, stochastic_matrix to be used to compute a transition matrix
 *         q_matrix q_matrix, q_matrix to be used to compute a transition matrix
 * @returns
 */
transition_matrix::transition_matrix( stochastic_matrix sto_matrix, q_matrix q_matrix )
        : matrix( transition_matrix::covert_to_transition( std::move( sto_matrix ), std::move( q_matrix ) ) ) {}

/*
 * computes a transition matrix
 * @params stochastic_matrix sto_matrix, stochastic_matrix to be used to compute a transition matrix
 *         q_matrix q_matrix, q_matrix to be used to compute a transition matrix
 * @returns matrix, computed matrix
 */
matrix transition_matrix::covert_to_transition( stochastic_matrix sto_matrix, q_matrix q_matrix ) {
    matrix lhs{ transition_matrix::p * sto_matrix };
    matrix rhs{ ( 1.0 - transition_matrix::p ) * q_matrix };
    return lhs + rhs;
}

