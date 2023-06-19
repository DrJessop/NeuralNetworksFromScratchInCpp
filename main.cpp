#include "nn.hpp"
#include <chrono>

void time_naive_matmul() {
    constexpr size_t dim = 200;
    auto A = create_matrix<dim, dim, float>(0);
    auto B = create_matrix<dim, dim, float>(0);

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++) {
        auto C = naive_matmul(A, B);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = (end - start);
    cout << "Naive matmul time took: " << elapsed_seconds.count() << "s" << endl;
}

void time_matmul() {
    constexpr size_t dim = 200;
    auto A = create_matrix<dim, dim, float>(0);
    auto B = transpose(create_matrix<dim, dim, float>(0));

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++) {
        auto C = matmul(A, B);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = (end - start);
    cout << "Matmul time took: " << elapsed_seconds.count() << "s" << endl;
}


int main() {
    // Some data structure to represent matrices
    array<array<int, 2>, 2> matrix = create_matrix<2, 2, int>(0);

    // Print out matrices
    // print_matrix(matrix);

    // Naive matrix multiplication
    auto A = create_matrix<2, 2, int>(0);
    auto B = create_matrix<2, 2, int>(0);
    // auto C = naive_matmul(A, B);

    // print_matrix(C);

    auto D = create_matrix<2, 2, int>(0);
    auto E_T = transpose(create_matrix<2, 2, int>(0));
    // print_matrix(E_T);
    auto F = matmul(D, E_T);
    // print_matrix(F);
    // auto F = create_matrix<2, 2, int>(0);

    time_naive_matmul();
    time_matmul();


    // Optimizing matrix multiplication

    // Separating the bias from matrix multiplication

}