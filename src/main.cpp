#include<iostream>
#include<vector>
#include<functional>
#include <bits/stdc++.h>
#include "../include/poisson_1d.h"

int main() {
    int n = 99;
    std::vector<double> x(n), u(n);
    
    // g(x) = 1 (constant source)
    solve_poisson_1d(n, x, u, [](double x_val) { return 1.0; });

    // Output the middle value (should be ~0.125 for g(x)=1)
    std::cout << "u(0.5) = " << u[n/2] << std::endl;

    // Compare with analytical solution u(x) = (1/2)x(1-x)
    double analytical = 0.5 * x[n/2] * (1 - x[n/2]);
    std::cout << "Analytical u(0.5) = " << analytical << std::endl;

    // Error norm
    std::cout << "Error norm = " << std::norm(u[n/2] - analytical) << std::endl;
    return 0;
}