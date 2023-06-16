#include <array>
#include <iostream>

using std::array;
using std::cout, std::endl;

template <size_t nr, size_t nc, typename T>
matrix<nr, nc, T>create_matrix(int start) {
    matrix<nr, nc, T> matrix;

    // Arange population
    // 2x2
    // [[start, start + 1],
    //  [start + 2, start + 3]]
    int val = start;
    for (int r = 0; r < nr; r++) {
        for (int c = 0; c < nc; c++) {
            matrix[r][c] = val;
            val++;
        }
    }

    return matrix;
}

template <size_t nr, size_t nc, typename T>
void print_matrix(const matrix<nr, nc, T>& matrix) {
    for (int r = 0; r < nr; r++) {
        for (int c = 0; c < nc; c++) {
            cout << matrix[r][c] << ", ";
        }
        cout << endl;
    }
}