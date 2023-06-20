#include <array>
#include <iostream>

using std::array;
using std::cout, std::endl;

template <size_t nr, size_t nc, typename T>
matrix<nr, nc, T> create_matrix(int start) {
    matrix<nr, nc, T> mat;

    // Arange population
    // 2x2
    // [[start, start + 1],
    //  [start + 2, start + 3]]
    int val = start;
    for (int r = 0; r < nr; r++) {
        for (int c = 0; c < nc; c++) {
            mat[r][c] = val;
            val++;
        }
    }

    return mat;
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

template <size_t nr, size_t inner, size_t nc, typename T>
matrix<nr, nc, T> naive_matmul(const matrix<nr, inner, T>& A, const matrix<inner, nc, T>& B) {
    matrix<nr, nc, T> result;

    for (size_t c = 0; c < nc; c++) {
        for (size_t r = 0; r < nr; r++) {
            result[r][c] = 0;
            for (size_t i = 0; i < inner; i++) {
                result[r][c] += A[r][i] * B[i][c];
            }
        }
    }

    return result;
}

template <size_t nr, size_t nc, typename T>
matrix<nc, nr, T> transpose(const matrix<nr, nc, T>& matrix) {
    ::matrix<nc, nr, T> result;

    for (size_t r = 0; r < nr; r++) {
        for (size_t c = 0; c < nc; c++) {
            result[c][r] = matrix[r][c];
        }
    }

    return result;
}

template <size_t nr, size_t inner, size_t nc, typename T>
matrix<nr, nc, T> matmul(const matrix<nr, inner, T>& A, const matrix<nc, inner, T>& B) {
    matrix<nr, nc, T> result = {};

    for (size_t r = 0; r < nr; r++) {
        const auto& A_row = A[r];
        auto& result_row = result[r];
        for (size_t c = 0; c < nc; c++) {
            const auto& B_col = B[c];

            T accum = 0;
            for (size_t i = 0; i < inner; i++) {
                accum += A_row[i] * B_col[i];
            }
            result_row[c] = accum;
        }
    }

    return result;
}