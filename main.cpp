#include "nn.hpp"

int main() {
    // Some data structure to represent matrices
    array<array<int, 2>, 2> matrix = create_matrix<2, 2, int>(0);

    // Print out matrices
    print_matrix(matrix);

    // Naive matrix multiplication
    auto A = create_matrix<2, 2, int>(0);
    auto B = create_matrix<2, 2, int>(0);
    auto C = naive_matmul(A, B);

    print_matrix(C);


    // Optimizing matrix multiplication

    // Separating the bias from matrix multiplication

}