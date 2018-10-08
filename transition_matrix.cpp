/*
* Created by Daniel Shin on 2018-10-08.
*/

#pragma once

#include "transition_matrix.hpp"

transition_matrix::transition_matrix( stochastic_matrix &sto_matrix, q_matrix &q_matrix ) {

}

matrix transition_matrix::covert_to_transition( stochastic_matrix sto_matrix, q_matrix q_matrix ) {
    matrix temp_sto{ sto_matrix * p };
    matrix temp_q( q_matrix * ( 1 - p ));
    return temp_sto + temp_q;
}

