#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    if (n == 1) {
        cout << a << endl;
        return 0;
    }
    int mn = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            cout << a << endl;
            return 0;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            cout << a << endl;
            return 0;
        }
    }
    swap(a[n - 2], a[n - 1]);
    cout << a << endl;
    return 0;
}