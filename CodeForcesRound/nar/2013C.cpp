#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int q(vector<char> &a) {
    cout << "? ";
    for (auto &x : a)
        if (x != 0) cout << char(x);
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<char> a(2 * n + 2, 0);
    int indexLeft = n;
    int indexRight = n + 1;
    int foundRight = 0;
    int ans;
    for (int i = 0; i < n; i++) {
        if (!foundRight) {
            a[indexRight] = '0';
            ans = q(a);
            if (ans == 1) {
                indexRight++;
                continue;
            }
            a[indexRight] = '1';
            ans = q(a);
            if (ans == 1) {
                indexRight++;
                continue;
            }
            foundRight = 1;
            a[indexRight] = 0;
        }
        a[indexLeft] = '0';
        ans = q(a);
        if (ans == 1) {
            indexLeft--;
            continue;
        }
        a[indexLeft] = '1';
        indexLeft--;
    }
    cout << "! ";
    for (auto &x : a)
        if (x != 0) cout << x;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}