#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int b[], int c[], int a_size, int b_size, int c_size) {
    int pos_b, pos_c;
    pos_b = pos_c = 0;
    for (int i = 0; i < a_size; i++) {
        if (pos_b == b_size) {
            a[i] = c[pos_c];
            pos_c++;
        } else {
            if (pos_c == c_size) {
                a[i] = b[pos_b];
                pos_b++;
            } else {
                if (b[pos_b] < c[pos_c]) {
                    a[i] = b[pos_b];
                    pos_b++;
                } else {
                    a[i] = c[pos_c];
                    pos_c++;
                }
            }
        }
    }
}

void merge_sort(int a[], int n) {
    if (n == 1) return;
    int mid = n / 2;
    int b[mid], c[n - mid];
    for (int i = 0; i < mid; i++) b[i] = a[i];
    for (int i = mid; i < n; i++) c[i - mid] = a[i];
    merge_sort(b, mid);
    merge_sort(c, n - mid);
    merge(a, b, c, n, mid, n - mid);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    merge_sort(a, n);
    cout << "Arreglo ordenado:" << endl;
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}