#include <bits/stdc++.h>
using namespace std;

int get_majority_element(vector<int> &a) {
  int n = a.size();
  sort(a.begin(), a.end());
  int maxi = 1;
  int cur = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      cur++;
    } else {
      cur = 1;
    }
    maxi = max(maxi, cur);
  }
  if (2 * maxi > n) return 1;
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << (get_majority_element(a) != -1) << '\n';
}
