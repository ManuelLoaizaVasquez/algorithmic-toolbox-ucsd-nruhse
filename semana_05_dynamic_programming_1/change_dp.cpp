#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int get_change(int money) {
  int dp[money + 1];
  vector<int> coins = {1, 3, 4};
  //vector<int> coins = {1, 8, 20};
  int size_coins = coins.size();
  for (int i = 0; i <= money; i++) dp[i] = INF;
  dp[0] = 0;
  for (int current = 1; current <= money; current++) {
    for (int coin = 0; coin < size_coins; coin++) {
      int from = current - coins[coin];
      if (from >= 0) {
        dp[current] = min(dp[current], dp[from] + 1);
      }
    }
  }
  return dp[money];
}

int main() {
  int n;
  cin >> n;
  cout << get_change(n) << endl;
  return 0;
}
