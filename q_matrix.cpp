/*
* Created by Daniel Shin on 2018-10-08.
*/

#pragma once

#include "q_matrix.hpp"

q_matrix::q_matrix( int size ) : matrix( size ) {
    for ( int i = 0; i < size; ++i )
        for ( int j = 0; j < size; ++j )
            set_value( i, j, 1.0 / size );
}

