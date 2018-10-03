#include <iostream>
#include "matrix.hpp"

int main() {
    double matrix_values[] = {1, 2, 3,
                              4, 5, 6,
                              7, 8, 9};
    int size {9};
    matrix my_matrix(matrix_values, size);

    cout << "============================" << endl;
    cout << "my_matrix values:" << endl;
    cout << my_matrix << endl;

    return 0;
}