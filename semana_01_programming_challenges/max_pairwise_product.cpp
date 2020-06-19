#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();
    int max1, max2;
    max1 = max2 = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] >= max1) {
            max2 = max1;
            max1 = a[i];
        } else {
            if (a[i] >= max2) {
                max2 = a[i];
            }
        }
    }
    max_product = max1 * max2;
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers); << "\n";
    return 0;
}
