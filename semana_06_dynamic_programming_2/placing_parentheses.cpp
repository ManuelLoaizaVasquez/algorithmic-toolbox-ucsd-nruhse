#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef pair<Long, Long> Pair;

const Long INF = 1e18;

Long eval(Long a, Long b, char op) {
  //cout << a << " " << b << " " << op << endl;
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

Long get_maximum_value(const string &exp) {
  // Separo los digitos de las operaciones
  vector<Long> digits;
  vector<char> operations;
  int sz = exp.size();
  for (int i = 0; i < sz; i++) {
    if (i % 2 == 0) digits.push_back((Long)(exp[i] - '0'));
    else operations.push_back(exp[i]);
  }
  /*
  for (int i = 0; i < digits.size(); i++) cout << digits[i] << " ";
  cout << endl;
  for (int i = 0; i < operations.size(); i++) cout << operations[i] << " ";
  cout << endl;
  */
  int n = digits.size();
  // dp[i][j].first = minimo valor de la expresion [i ... j]
  // dp[i][j].second = maximo valor de la expresion [i ... j]
  vector<vector<Pair>> dp(n, vector<Pair>(n));
  // Iniciamos el DP con los casos base
  for (int i = 0; i < n; i++) dp[i][i].first = dp[i][i].second = digits[i];
  // Para cada longitud posible, tratamos de resolver el problema
  for (int len = 1; len <= n - 1; len++) {
    for (int left = 0; left <= n - len - 1; left++) {
      int right = left + len;
      Long mini = INF;
      Long maxi = -INF;
      for (int op = left; op < right; op++) {
        char sym = operations[op];  
        //cout << "[" << left << " " << sym << " " << right << "]" << endl;
        Long temp_1 = eval(dp[left][op].first, dp[op + 1][right].first, sym);
        Long temp_2 = eval(dp[left][op].first, dp[op + 1][right].second, sym);
        Long temp_3 = eval(dp[left][op].second, dp[op + 1][right].first, sym);
        Long temp_4 = eval(dp[left][op].second, dp[op + 1][right].second, sym);
        mini = min(mini, min(temp_1, min(temp_2, min(temp_3, temp_4))));
        maxi = max(maxi, max(temp_1, max(temp_2, max(temp_3, temp_4))));
      }
      // Memoizamos
      dp[left][right].first = mini;
      dp[left][right].second = maxi;
    }
  }
  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i > j) cout << "* ";
      else cout << dp[i][j].first << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i > j) cout << "* ";
      else cout << dp[i][j].second << " ";
    }
    cout << endl;
  }
  */
  return dp[0][n - 1].second;
}

int main() {
  string s;
  cin >> s;
  cout << get_maximum_value(s) << endl;
}
