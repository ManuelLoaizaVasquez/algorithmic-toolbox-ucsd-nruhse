#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

Long fibonacci_sum_fast(Long n) {
    Long sz = 1000;
    Long f[sz];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < sz; i++) f[i] = (f[i - 1] + f[i - 2]) % 10;
    Long sum[sz];
    sum[0] = f[0];
    for (int i = 1; i < sz; i++) sum[i] = (sum[i - 1] + f[i]) % 10;
    Long period;
    for (int i = 2; i < sz - 1; i++) {
        if (sum[i] == 0 and sum[i + 1] == 1) {
            period = i;
            break;
        }
    }
    return sum[n % period];
}

int main() {
    long long n = 0;
    cin >> n;
    //std::cout << fibonacci_sum_naive(n);
    cout << fibonacci_sum_fast(n) << '\n';
    return 0;
}
