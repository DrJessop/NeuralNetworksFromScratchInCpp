#include <array>
#include <iostream>

using std::array;
using std::cout, std::endl;

template <size_t nr, size_t nc, typename T>
array<array<T, nc>, nr> create_matrix(int start) {
    array<array<T, nc>, nr> matrix;

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
void print_matrix(const array<array<T, nc>, nr>& matrix) {
    for (int r = 0; r < nr; r++) {
        for (int c = 0; c < nc; c++) {
            cout << matrix[r][c] << ", ";
        }
        cout << endl;
    }
}