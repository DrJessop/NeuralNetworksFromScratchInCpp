#include "nn.hpp"

template <size_t nr, size_t inner, size_t nc, size_t iter>
void time_naive_matmul() {
    auto A = create_matrix<nr, inner, int>(0);
    auto B = create_matrix<inner, nc, int>(0);

    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < iter; i++) {
        naive_matrix_multiply(A, B);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "TOTAL TIME FOR NAIVE MATRIX MULTIPLY: " << elapsed_seconds.count() << "s" << endl;
}

template <size_t nr, size_t inner, size_t nc, size_t iter>
void time_matmul() {
    auto A = create_matrix<nr, inner, int>(0);
    auto B = create_matrix<inner, nc, int>(0);

    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < iter; i++) {
        matrix_multiply(A, B);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "TOTAL TIME FOR MATRIX MULTIPLY: " << elapsed_seconds.count() << "s" << endl;
}

int main() {
    // Some data structure to represent matrices
    matrix<2, 2, int> matrix = create_matrix<2, 2, int>(0);

    // Print out matrices
    // print_matrix(matrix);

    // Naive matrix multiplication
    auto A = create_matrix<2, 2, int>(0);
    auto B = create_matrix<2, 2, int>(0);

    auto C_naive = naive_matrix_multiply(A, B);

    cout << endl;
    // print_matrix(C_naive);

    auto B_rm = transpose(B);
    cout << endl;
    // print_matrix(B_rm);

    cout << endl;
    auto C = matrix_multiply(A, B_rm);
    // print_matrix(C);

    constexpr size_t nr = 500;
    constexpr size_t inner = 500;
    constexpr size_t nc = 500;

    time_naive_matmul<nr, inner, nc, 20>();
    time_matmul<nr, inner, nc, 20>();

    // Separating the bias from matrix multiplication

    // Optimizing matrix multiplication + bias
}