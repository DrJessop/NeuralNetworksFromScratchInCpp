#include <array>

using std::array;

template <size_t nr, size_t nc, typename T>
array<array<T, nc>, nr> create_matrix(int start);

template <size_t nr, size_t nc, typename T>
void print_matrix(const array<array<T, nc>, nr>& matrix);

#include "nn.tpp"