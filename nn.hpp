#include <array>

using std::array;

template <size_t nr, size_t nc, typename T>
using matrix = array<array<T, nc>, nr>;

template <size_t nr, size_t nc, typename T>
matrix<nr, nc, T> create_matrix(int start);

template <size_t nr, size_t nc, typename T>
void print_matrix(const matrix<nr, nc, T>& matrix);

template <size_t nr, size_t inner, size_t nc, typename T>
matrix<nr, nc, T> naive_matrix_multiply(const matrix<nr, inner, T>& A, const matrix<inner, nc, T>& B) {
    matrix<nr, nc, T> res;

    for (size_t r = 0; r < nr; r++) {
        for (size_t c = 0; c < nc; c++) {
            T accum = 0;
            for (size_t i = 0; i < inner; i++) {
                accum += A[r][i] * B[i][c];
            }
            res[r][c] = accum;
        }
    }

    return res;
}

template <size_t nr, size_t nc, typename T>
matrix<nc, nr, T> transpose(const matrix<nr, nc, T>& matrix) {
    ::matrix<nc, nr, T> res;
    for (size_t r = 0; r < nr; r++) {
        for (size_t c = 0; c < nc; c++) {
            res[c][r] = matrix[r][c];
        }
    }

    return res;
}

template <size_t nr, size_t inner, size_t nc, typename T>
matrix<nr, nc, T> matrix_multiply(const matrix<nr, inner, T>& A, const matrix<inner, nc, T>& B_rm) {
    matrix<nr, nc, T> res;

    for (size_t r = 0; r < nr; r++) {
        const auto& row = A[r];
        for (size_t c = 0; c < nc; c++) {
            T accum = 0;
            const auto& col = B_rm[c];
            for (size_t i = 0; i < inner; i++) {
                accum += row[i] * col[i];
            }
            res[r][c] = accum;
        }
    }

    return res;
}

#include "nn.tpp"