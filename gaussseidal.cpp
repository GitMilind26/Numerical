#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to implement Gauss-Seidel method
vector<double> gaussSeidel(vector<vector<double>> A, vector<double> b, vector<double> x0, double tolerance, int maxIterations) {
    int n = A.size();
    vector<double> x = x0;
    vector<double> x_new(n);

    for (int iter = 0; iter < maxIterations; ++iter) {
        for (int i = 0; i < n; ++i) {
            x_new[i] = b[i];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    x_new[i] -= A[i][j] * x[j];
                }
            }
            x_new[i] /= A[i][i];
            x[i] = x_new[i]; // Update x with the new value immediately
        }

        // Check for convergence
        double error = 0.0;
        for (int i = 0; i < n; ++i) {
            error += abs(x_new[i] - x[i]);
        }
        if (error < tolerance) {
            cout << "Converged after " << iter + 1 << " iterations." << endl;
            return x;
        }
    }
    cout << "Maximum iterations reached, method did not converge." << endl;
    return x;
}

int main() {
    // Example usage
    vector<vector<double>> A = {
        {4, -1, 0},
        {-1, 4, -1},
        {0, -1, 4}
    };

    vector<double> b = {15, 10, 10};
    vector<double> x0 = {0, 0, 0}; // Initial guess

    double tolerance = 0.0001;
    int maxIterations = 100;

    vector<double> result = gaussSeidel(A, b, x0, tolerance, maxIterations);

    cout << "Solution:" << endl;
    cout << fixed << setprecision(6);
    for (int i = 0; i < result.size(); ++i) {
        cout << "x" << i + 1 << " = " << result[i] << endl;
    }

    return 0;
}
