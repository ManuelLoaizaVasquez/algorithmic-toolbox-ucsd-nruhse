#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> &a, int l, int mid, int r) {
  vector<int> b, c;
  for (int i = l; i <= mid; i++) b.push_back(a[i]);
  for (int i = mid + 1; i <= r; i++) c.push_back(a[i]);
  int b_size = mid - l + 1;
  int c_size = r - mid;
  long long inversions = 0;
  int b_pos, c_pos;
  b_pos = c_pos = 0;
  for (int i = l; i <= r; i++) {
    if (b_pos == b_size) {
      a[i] = c[c_pos];
      c_pos++;
    } else {
      if (c_pos == c_size) {
        a[i] = b[b_pos];
        b_pos++;
      } else {
        if (c[c_pos] < b[b_pos]) {
          inversions += (b_size - b_pos);
          a[i] = c[c_pos];
          c_pos++;
        } else {
          a[i] = b[b_pos];
          b_pos++;
        }
      }
    }
  }
  return inversions;
}

long long get_number_of_inversions(vector<int> &a, int l, int r) {
  long long inversions = 0LL;
  if (l == r) return inversions;
  int mid = (l + r) / 2;
  inversions += get_number_of_inversions(a, l, mid);
  inversions += get_number_of_inversions(a, mid + 1, r);
  inversions += merge(a, l, mid, r);
  return inversions;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) cin >> a[i];
  cout << get_number_of_inversions(a, 0, n - 1) << endl;
}
