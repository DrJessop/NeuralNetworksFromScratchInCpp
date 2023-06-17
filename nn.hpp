#include <array>

using std::array;

template <size_t nr, size_t nc, typename T>
using matrix = array<array<T, nc>, nr>;

template <size_t nr, size_t nc, typename T>
matrix<nr, nc, T> create_matrix(int start);

template <size_t nr, size_t nc, typename T>
void print_matrix(const matrix<nr, nc, T>& matrix);

template <size_t nr, size_t inner, size_t nc, typename T>
matrix<nr, nc, T> naive_matmul(const matrix<nr, inner, T>& A, const matrix<inner, nc, T>& B);

#include "nn.tpp"