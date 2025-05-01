#include <iostream>
#include <cmath>

using namespace std;

// Function for which we are finding the root
double f(double x) {
    return x*x - 4; // Example: x^2 - 4 = 0
}

// Secant method function
double secantMethod(double x0, double x1, int maxIter, double tol) {
    double x2;
    for (int i = 0; i < maxIter; i++) {
        if (fabs(f(x1) - f(x0)) < tol) {
            cout << "Divide by zero error.\n";
            return x1;
        }

        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        
        if (fabs(x2 - x1) < tol) {
            return x2;
        }
        
        x0 = x1;
        x1 = x2;
    }
    
    return x2;
}

int main() {
    double x0 = 1.0, x1 = 2.0; // Initial guesses
    int maxIter = 100;
    double tol = 1e-6; // Tolerance level

    double root = secantMethod(x0, x1, maxIter, tol);
    cout << "Root found: " << root << endl;

    return 0;
}
