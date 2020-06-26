#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int cur = 1;
  while (true) {
    int rem = n - cur;
    if (cur < rem) {
      summands.push_back(cur);
      n = rem;
    } else {
      summands.push_back(n);
      break;
    }
    cur++;
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
