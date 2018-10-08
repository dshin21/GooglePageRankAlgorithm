/*
* Created by Daniel Shin on 2018-10-07.
*/

#pragma once

#include "importance_matrix.hpp"

class stochastic_matrix : public importance_matrix {
    static importance_matrix convert_to_stochastic( importance_matrix );

public:
    explicit stochastic_matrix( importance_matrix & );
};


