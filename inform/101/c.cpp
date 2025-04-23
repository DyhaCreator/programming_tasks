#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int m;
    cin >> m;
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        if (i < m - 1 || i > m - 1) {
            cout << a[i];
        }
    }
    cout << endl;
    return 0;
}