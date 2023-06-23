#include <chrono>

#include "nn.hpp"

void time_naive_matmul() {
    constexpr size_t dim = 200;
    constexpr size_t loopcount = 200;
    auto A = create_matrix<dim, dim, int>(0);
    auto B = create_matrix<dim, dim, int>(0);

    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < loopcount; i++) {
        naive_matmul(A, B);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "Naive matmul took " << elapsed_seconds.count() << " seconds" << endl;
}

void time_matmul() {
    constexpr size_t dim = 200;
    constexpr size_t loopcount = 200;
    auto A = create_matrix<dim, dim, int>(0);
    auto B = transpose(create_matrix<dim, dim, int>(0));

    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < loopcount; i++) {
        matmul(A, B);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "Matmul took " << elapsed_seconds.count() << " seconds" << endl;
}

int main() {

    // Optimizing matrix multiplication
    // time_naive_matmul();
    // time_matmul();

    // Separating the bias from matrix multiplication
    auto A = create_matrix<2, 2, int>(0);
    auto B = transpose(create_matrix<2, 2, int>(0));
    auto b = create_bias<2, int>(0);

    auto C = matmul(A, B);
    print_matrix(C);
    cout << endl;
    auto C_plus_bias = matmul_plus_bias(A, B, b);


    print_matrix(C_plus_bias);

}