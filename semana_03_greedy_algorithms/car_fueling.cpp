#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int left, right, ans;
    left = right = ans = 0;
    int sz = stops.size();
    while (left < sz - 1) {
        right = left + 1;
        while (right < sz) {
            if (stops[right] - stops[left] <= tank) {
                right++;
            } else {
                right--;
                break;
            }
        }
        if (left == right) return -1;
        ans++;
        left = right;
    }
    return ans - 1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops;
    stops.push_back(0);
    for (size_t i = 0; i < n; ++i) {
        int stop;
        cin >> stop;
        stops.push_back(stop);
    }
    stops.push_back(d);
    cout << compute_min_refills(d, m, stops) << "\n";
    return 0;
}
