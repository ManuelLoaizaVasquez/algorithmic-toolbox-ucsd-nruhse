#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

vector<int> optimal_sequence(int n) {
  // Calculamos el DP
  int dp[n + 1];
  for (int i = 0; i <= n; i++) dp[i] = INF;
  dp[0] = dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    int from = i - 1;
    if (from > 0) {
      dp[i] = min(dp[i], dp[from] + 1);
    }
    if (i % 2 == 0) {
      from = i / 2;
      dp[i] = min(dp[i], dp[from] + 1);
    }
    if (i % 3 == 0) {
      from = i / 3;
      dp[i] = min(dp[i], dp[from] + 1);
    }
  }
  // Reconstruimos la solucion
  vector<int> sequence;
  while (n > 1) {
    sequence.push_back(n);
    int temp_1 = dp[n - 1];
    int temp_2 = (n % 2 == 0 ? dp[n / 2] : INF);
    int temp_3 = (n % 3 == 0 ? dp[n / 3] : INF);
    int mini = min(temp_1, min(temp_2, temp_3));
    if (mini == temp_1) {
      n--;
    } else {
      if (mini == temp_2) {
        n /= 2;
      } else {
        n /= 3;
      }
    }
  }
  sequence.push_back(1);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
