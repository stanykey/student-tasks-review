#include <iostream>

using namespace std;

void output(int N, int** matrix)
{
    cout << "---------------------------------------------------------------\n";
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] < 10)
                cout << " ";
            cout << matrix[i][j] << "| ";
            count += 1;
        }
        if (count == N) { cout << "\n"; count = 0; }
    }
}
int** generator_matrix(int N, int** matrix)
{
    for (int i = 0; i < N; i++)
        matrix[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = rand() % 50;
        }
    return matrix;
}
int** cocktail(int N, int** matrix)
{
    int tmp;
    for (int p = 0; p < N; p++)
    {
        for (int j = 0; j < N-1; j++)
            for (int i = 0; i < N-1; i++)
            {
                if (matrix[j][i] > matrix[j+1][i])
                {
                    tmp = matrix[j][i];
                    matrix[j][i] = matrix[j+1][i];
                    matrix[j+1][i] = tmp;
                }
            }
    }
    return matrix;
}

int main()
{
    int N;
    cin >> N;
    int** matrix = new int* [N];
    generator_matrix(N, matrix);
    output(N, matrix);
    cocktail(N, matrix);
    output(N, matrix);
}
