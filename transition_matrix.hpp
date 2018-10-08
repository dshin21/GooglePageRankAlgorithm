/*
* Created by Daniel Shin on 2018-10-08.
*/

#pragma once

#include "matrix.hpp"
#include "stochastic_matrix.hpp"
#include "q_matrix.hpp"

class transition_matrix : public matrix {
    static matrix covert_to_transition( stochastic_matrix, q_matrix );

public:
    static constexpr double p = 0.85;

    transition_matrix( stochastic_matrix &, q_matrix & );
};


