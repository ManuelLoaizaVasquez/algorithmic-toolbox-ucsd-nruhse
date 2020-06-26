#include <bits/stdc++.h>
using namespace std;

bool desc(const pair<double, int>& a, const pair<double, int>& b) { return a.first > b.first; }

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  // write your code here
  int n = values.size();
  pair<double, int> ratio[n];
  for (int i = 0; i < n; i++) {
    ratio[i].first = ((double) values[i]) / weights[i];
    ratio[i].second = i;
  }
  sort(ratio, ratio + n, desc);
  for (int i = 0; i < n; i++) {
    int who = ratio[i].second;
    int amount = min(capacity, weights[who]);
    value += ratio[i].first * amount;
    capacity -= amount;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
