#include <bits/stdc++.h>
using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n = w.size();
  vector<vector<int>> dp(W + 1, vector<int>(n + 1));
  for (int i = 0; i <= W; i++) dp[i][0] = 0;
  for (int i = 0; i <= n; i++) dp[0][i] = 0;
  for (int pos = 1; pos <= n; pos++) {
    for (int weight = 1; weight <= W; weight++) {
      dp[weight][pos] = dp[weight][pos - 1];
      int prev = weight - w[pos - 1];
      if (prev >= 0) {
        dp[weight][pos] = max(dp[weight][pos], dp[prev][pos - 1] + w[pos - 1]);
      }
    }
  }
  return dp[W][n];
}

int main() {
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << optimal_weight(W, w) << '\n';
}
