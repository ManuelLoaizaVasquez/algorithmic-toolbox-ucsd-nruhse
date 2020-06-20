#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

Long fibonacci_sum_square_fast(Long n) {
    Long m = 10;
    Long sz = m * m;
    Long f[sz + 1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= sz; i++) f[i] = (f[i - 1] + f[i - 2]) % m;
    Long period;
    for (int i = 2; i < sz; i++) {
        if (f[i] == 0 and f[i + 1] == 1) {
            period = i;
            break;
        }
    }
    return (f[n % period] * f[(n + 1) % period]) %  m;
}

int main() {
    long long n = 0;
    cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n);
    cout << fibonacci_sum_square_fast(n) << '\n';
    return 0;
}
