#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

Long get_fibonacci_huge_fast(Long n, Long m) {
    Long sz = m * m;
    Long f[sz + 1];
    f[0] = 0;
    f[1] = 1;
    for (Long i = 2; i <= sz; i++) f[i] = (f[i - 1] + f[i - 2]) % m;
    Long period;
    for (Long i = 2; i < sz; i++) {
        if (f[i] == 0 and f[i + 1] == 1) {
            period = i;
            break;
        }
    }
    return f[n % period];
}

int main() {
    long long n, m;
    cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    cout << get_fibonacci_huge_fast(n, m) << '\n';
    return 0;
}