#include<iostream>
#include<vector>
#include<functional>
#include "../include/poisson_1d.h"

int main() {
    int n = 99;
    std::vector<double> x(n), u(n);
    
    // Using a lambda for g(x) = 1 (constant source)
    solve_poisson_1d(n, x, u, [](double x_val) { return 1.0; });

    // Output the middle value (should be ~0.125 for g(x)=1)
    std::cout << "u(0.5) = " << u[n/2] << std::endl;
    
    return 0;
}