
#include "matrix.hpp"
#include "connectivity_matrix.hpp"
#include "transition_matrix.hpp"
#include "column_matrix.hpp"

using namespace std;

int main() {
    connectivity_matrix conn_matrix = connectivity_matrix::read_file(
            "connectivity.txt" );
    cout << "Connectivity Matrix" << endl;
    cout << conn_matrix << endl;

    importance_matrix imp_matrix( conn_matrix );
    cout << "Importance Matrix" << endl;
    cout << imp_matrix << endl;

    stochastic_matrix stoch_matrix( imp_matrix );
    cout << "Stochastic Matrix" << endl;
    cout << stoch_matrix << endl;

    q_matrix q_matrix( conn_matrix.get_matrix_row() );
    cout << "Q Matrix" << endl;
    cout << q_matrix << endl;

    transition_matrix trans_matrix( stoch_matrix, q_matrix );
    cout << "Transition Matrix" << endl;
    cout << trans_matrix << endl;

    column_matrix col_matrix( conn_matrix.get_matrix_row() );
    cout << "Column matrix" << endl;
    cout << col_matrix << endl;

    column_matrix result = col_matrix.markov_process( trans_matrix );
    cout << "After Markov process" << endl;
    cout << result << endl;

    cout << "Scaled matrix" << endl;
    result.scale_rank();

    char page_name{ 'A' };
    for ( int i = 0; i < result.get_matrix_row(); ++i )
        cout << "Page " << page_name++ << " : " << setprecision( 2 ) << fixed << result.get_value( i, 0 ) * 100.0 << "%" << endl;

    return 0;
}