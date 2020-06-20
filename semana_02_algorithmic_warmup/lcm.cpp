#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

Long gcd_fast(Long a, Long b) {
  if (b == 0) return a;
  return gcd_fast(b, a % b);
}

Long lcm_fast(Long a, Long b) {
  return a / gcd_fast(max(a, b), min(a, b)) * b;
}

int main() {
  Long a, b;
  cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  cout << lcm_fast(a, b) << endl;
  return 0;
}
