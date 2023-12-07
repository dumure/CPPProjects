#include <iostream>
#include <iomanip>

int main() {
    int m, n, k;

    // Input
    std::cin >> m >> n >> k;

    // Output with specified decimal places
    std::cout << std::fixed << std::setprecision(k) << static_cast<double>(m) / n << std::endl;

    return 0;
}