#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        if (a[i] + b[i] - 2 * '0' == 0)
            c[i] = 1;
        if (a[i] + b[i] - 2 * '0' == 1)
            c[i] = 2;
        if (a[i] + b[i] - 2 * '0' == 2)
            c[i] = 0;
    }
    /*for (auto &x : c)
        cout << x << " ";
    cout << endl;*/
    c.push_back(INF);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] == 1 && c[i + 1] == 0) {
            sum += 2;
            // cout << 2 << " ";
            i++;
        } else if (c[i] == 0 && c[i + 1] == 1) {
            sum += 2;
            // cout << 2 << " ";
            i++;
        } else {
            sum += c[i];
            // cout << c[i] << " ";
        }
        // cout << sum << " ";
    }
    // cout << endl;
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}