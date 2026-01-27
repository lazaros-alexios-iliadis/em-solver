#include<vector>    
#include<cmath>
#include<functional>
#include "../include/poisson_1d.h"

// Solve the 1D Poisson equation -u''(x) = f(x) on (0,1) with Dirichlet boundary conditions u(0)=u(1)=0
// We use the finite difference method and the Thomas algorithm for tridiagonal systems.
// Time complexity: O(n) -- Space complexity: O(n)

void solve_poisson_1d(int n, std::vector<double>& x, std::vector<double>& u, std::function<double(double)> g) {
    double h = 1.0 / (n + 1);
    std::vector<double> a(n, -1.0), b(n, 2.0), c(n, -1.0), f(n);

    // Set up the right-hand side f
    for (int i = 0; i < n; ++i) {
        x[i] = (i + 1) * h;
        f[i] = h * h * g(x[i]);
    }

    // Forward elimination
    for (int i = 1; i < n; ++i) {
        double m = a[i] / b[i - 1];
        b[i] -= m * c[i - 1];
        f[i] -= m * f[i - 1];
    }

    // Back substitution
    u[n - 1] = f[n - 1] / b[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        u[i] = (f[i] - c[i] * u[i + 1]) / b[i];
    }
}