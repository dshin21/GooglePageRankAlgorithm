#pragma once

#include "matrix.hpp"
#include "transition_matrix.hpp"

class column_matrix : public matrix {
public:
    explicit column_matrix( int size );

    column_matrix( const column_matrix& col_matrix );

    column_matrix( transition_matrix& tran_matrix, column_matrix& col_matrix );

    column_matrix markov_process( transition_matrix tran_matrix );

    void scale_rank();
};