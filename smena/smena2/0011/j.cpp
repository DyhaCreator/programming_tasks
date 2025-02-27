#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int l = 0;
    int r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (m * (m + 1) / 2 <= n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << r << endl;
    vector<vector<int>> a(r);
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = i + 1; j < r; j++) {
            a[i].push_back(cnt);
            a[j].push_back(cnt);
            cnt++;
        }
    }
    for (auto &x : a) {
        for (auto &y : x) 
            cout << y + 1 << " ";
        cout << endl;
    }
    return 0;
}