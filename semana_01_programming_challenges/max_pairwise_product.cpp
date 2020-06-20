#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

Long MaxPairwiseProduct(const std::vector<Long>& numbers) {
    Long max_product = 0;
    Long n = numbers.size();
    Long max1, max2;
    max1 = max2 = -1;
    for (int i = 0; i < n; i++) {
        if (numbers[i] >= max1) {
            max2 = max1;
            max1 = numbers[i];
        } else {
            if (numbers[i] >= max2) {
                max2 = numbers[i];
            }
        }
    }
    max_product = max1 * max2;
    return max_product;
}

int main() {
    Long n;
    std::cin >> n;
    std::vector<Long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
