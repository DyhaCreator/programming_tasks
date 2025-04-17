#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : a) {
        int f = 0;
        for (auto &y : a) {
            if (x != y && x % y == 0) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            cout << x << " ";
        }
    }
    cout << endl;
    return 0;
}