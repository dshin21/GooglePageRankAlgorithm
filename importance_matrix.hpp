/*
* Created by Daniel Shin on 2018-10-07.
*/

#pragma once

#include "matrix.hpp"
#include "connectivity_matrix.hpp"

class importance_matrix : public matrix {
    static matrix convert_to_importance(connectivity_matrix);
    static double sum_col( matrix, int );

public:
    explicit importance_matrix( connectivity_matrix & );

};


