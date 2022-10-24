#include <iostream>


//
// i/o
//
int read_int() {
    int value = 0;
    std::cin >> value;
    return value;
}

void print_matrix(const int* const* matrix, std::size_t dimension) {
    int count = 0;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (matrix[i][j] < 10) std::cout << " ";
            std::cout << matrix[i][j] << "| ";
            count++;
        }

        if (count == dimension) {
            std::cout << "\n";
            count = 0;
        }
    }
}

int** generator_matrix(std::size_t dimension) {
    int** matrix = new int*[dimension];

    for (int i = 0; i < dimension; i++) {
        matrix[i] = new int[dimension];
    }

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            matrix[i][j] = rand() % 50;
        }
    }

    return matrix;
}


//
// solution
//
int** sort_matrix_columns(int** matrix, std::size_t dimension) {
    for (int p = 0; p < dimension; p++) {
        for (int j = 0; j < dimension - 1; j++) {
            for (int i = 0; i < dimension - 1; i++) {
                if (matrix[j][i] > matrix[j + 1][i]) {
                    int tmp          = matrix[j][i];
                    matrix[j][i]     = matrix[j + 1][i];
                    matrix[j + 1][i] = tmp;
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
    const std::size_t dimension = read_int();
    int** matrix = generator_matrix(dimension);
    print_matrix(matrix, dimension);

    sort_matrix_columns(matrix, dimension);
    print_matrix(matrix, dimension);

    return 0;
}
