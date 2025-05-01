#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to print the matrix
void printMatrix(const vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to perform Gaussian elimination
vector<double> gaussianElimination(vector<vector<double>> matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        // Partial pivoting (find the row with the largest absolute value in the current column)
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(matrix[k][i]) > abs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }

        // Swap rows
        if (maxRow != i) {
            swap(matrix[i], matrix[maxRow]);
        }

        // Eliminate elements below the current pivot
        for (int k = i + 1; k < n; ++k) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < n + 1; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Back substitution to find the solution
    vector<double> solution(n);
    for (int i = n - 1; i >= 0; --i) {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; ++j) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }
    return solution;
}

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));
    cout << "Enter the augmented matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Input Matrix:" << endl;
    printMatrix(matrix);

    vector<double> solution = gaussianElimination(matrix);

    cout << "Solution:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}
