#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

Long get_fibonacci_partial_sum_fast(Long from, Long to) {
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
    return ((sum[to % period] - (from == 0 ? 0 : sum[(from - 1) % period])) + 10) % 10;
}

int main() {
    long long from, to;
    cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
    return 0;
}
