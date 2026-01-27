#pragma once
#include <vector>
#include <functional>

void solve_poisson_1d(int n, std::vector<double>& x, std::vector<double>& u, std::function<double(double)> g);