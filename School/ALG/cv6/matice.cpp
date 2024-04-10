#include <iostream>
#include <vector>
#include <cmath>

// Definice operací pro maticové funkce
typedef std::vector<std::vector<double>> Matrix;

// Funkce pro výpočet faktoriálu
double factorial(int n) {
    double result = 1.0;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Operace pro sčítání matic
Matrix matrix_addition(const Matrix& A, const Matrix& B) {
    int rows = A.size();
    int cols = A[0].size();
    Matrix result(rows, std::vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Operace pro násobení matic
Matrix matrix_multiplication(const Matrix& A, const Matrix& B) {
    int rows_A = A.size();
    int cols_A = A[0].size();
    int cols_B = B[0].size();
    Matrix result(rows_A, std::vector<double>(cols_B, 0.0));
    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            for (int k = 0; k < cols_A; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Funkce pro výpočet exp(4)
Matrix matrix_exp(const Matrix& A, int N) {
    int M = A.size();
    Matrix result(M, std::vector<double>(M, 0.0));
    Matrix term = Matrix(M, std::vector<double>(M, 0.0));
    Matrix identity = Matrix(M, std::vector<double>(M, 0.0));
    for (int i = 0; i < M; ++i) {
        identity[i][i] = 1.0;
    }
    for (int n = 0; n < N; ++n) {
        term = matrix_multiplication(identity, A);
        for (int i = 2; i <= n; ++i) {
            term = matrix_multiplication(term, A);
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                result[i][j] += term[i][j] / factorial(n);
            }
        }
    }
    return result;
}

// Funkce pro výpočet sin(A)
Matrix matrix_sin(const Matrix& A, int N) {
    int M = A.size();
    Matrix result(M, std::vector<double>(M, 0.0));
    Matrix term = A;
    Matrix power = A;
    for (int n = 0; n < N; ++n) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                result[i][j] += term[i][j] / std::tgamma(2 * n + 2);
            }
        }
        power = matrix_multiplication(power, A);
        term = matrix_multiplication(power, A);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                result[i][j] -= term[i][j] / std::tgamma(2 * n + 3);
            }
        }
    }
    return result;
}

// Funkce pro výpočet cos(A)
Matrix matrix_cos(const Matrix& A, int N) {
    int M = A.size();
    Matrix result(M, std::vector<double>(M, 0.0));
    Matrix term = Matrix(M, std::vector<double>(M, 0.0));
    Matrix identity = Matrix(M, std::vector<double>(M, 0.0));
    for (int i = 0; i < M; ++i) {
        identity[i][i] = 1.0;
    }
    for (int n = 0; n < N; ++n) {
        if (n % 2 == 0) {
            term = identity;
        } else {
            term = A;
        }
        for (int i = 0; i < 2 * n; ++i) {
            term = matrix_multiplication(term, A);
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                result[i][j] += term[i][j] / std::tgamma(2 * n + 2);
            }
        }
    }
    return result;
}

int main() {
    // Testování funkcí
    Matrix A = {{1, 2}, 
                {3, 4}};
    int N = 10; // Počet členů Taylorovy řady
    Matrix exp_A = matrix_exp(A, N);
    Matrix sin_A = matrix_sin(A, N);
    Matrix cos_A = matrix_cos(A, N);

    std::cout << "exp(A) = \n";
    for (const auto& row : exp_A) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nsin(A) = \n";
    for (const auto& row : sin_A) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\ncos(A) = \n";
    for (const auto& row : cos_A) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
