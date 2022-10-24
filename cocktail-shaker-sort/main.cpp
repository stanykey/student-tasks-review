#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-owning-memory"
#include <iostream>
#include <iomanip>


//
// i/o
//
int read_int(const char* prompt = "") {
    std::cout << prompt;

    int value = 0;
    std::cin >> value;
    std::cout << std::endl;
    return value;
}

void print_matrix(const int* const* matrix, std::size_t dimension, std::streamsize cell_width = 2) {
    for (int row = 0; row < dimension; row++) {
        std:: cout << "|";
        for (int col = 0; col < dimension; col++) {
            std::cout << std::setw(cell_width) << matrix[row][col] << "|";
        }
        std::cout << '\n';
    }

    std::cout << std::endl;
}

int** generate_matrix(std::size_t dimension) {
    int** matrix = new int*[dimension];
    for (int row = 0; row < dimension; row++) {
        matrix[row] = new int[dimension];
    }

    static const int MaxValue = 50;
    for (int row = 0; row < dimension; row++) {
        for (int col = 0; col < dimension; col++) {
            matrix[row][col] = rand() % MaxValue;
        }
    }

    return matrix;
}

void delete_matrix(int** matrix, std::size_t dimension) {
    for (int row = 0; row < dimension; row++) {
        delete[] matrix[row];
    }
    delete[] matrix;
}

//
// solution
//
int** sort_matrix_columns(int** matrix, std::size_t dimension) {
    for (int p = 0; p < dimension; p++) {
        for (int col = 0; col < dimension - 1; col++) {
            for (int row = 0; row < dimension - 1; row++) {
                if (matrix[col][row] > matrix[col + 1][row]) {
                    int tmp          = matrix[col][row];
                    matrix[col][row]     = matrix[col + 1][row];
                    matrix[col + 1][row] = tmp;
                }
            }
        }
    }

    return matrix;
}


//
// application entry point
//
int main() {
    const std::size_t dimension = read_int("enter matrix dimension: ");
    int** matrix = generate_matrix(dimension);
    print_matrix(matrix, dimension);

    sort_matrix_columns(matrix, dimension);
    print_matrix(matrix, dimension);

    delete_matrix(matrix, dimension);
    return 0;
}

#pragma clang diagnostic pop
