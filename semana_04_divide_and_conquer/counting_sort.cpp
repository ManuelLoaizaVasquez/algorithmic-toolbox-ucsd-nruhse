#include <bits/stdc++.h>
using namespace std;

void counting_sort(int a[], int n) {
    int maxi = a[0];
    for (int i = 0; i < n; i++) maxi = max(a[i], maxi);
    int freq[maxi + 1];
    for (int i = 0; i <= maxi; i++) freq[i] = 0;
    for (int i = 0; i < n; i++) freq[a[i]]++;
    int pos = 0;
    for (int i = 0; i <= maxi; i++) {
        while (freq[i] > 0) {
            a[pos] = i;
            freq[i]--;
            pos++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    counting_sort(a, n);
    cout << "Arreglo ordenado:" << endl;
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}