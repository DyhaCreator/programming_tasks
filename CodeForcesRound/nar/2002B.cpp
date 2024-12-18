#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> b(n);
    for (auto &x : b)
        cin >> x;
    int la = 0, ra = n - 1;
    int lb = 0, rb = n - 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[la] != b[lb] && a[la] != b[rb]) {
            cout << "Alice" << endl;
            return;
        }
        if (a[ra] != b[lb] && a[ra] != b[rb]) {
            cout << "Alice" << endl;
            return;
        }
        if (a[la] == b[lb]) {
            la++;
            lb++;
        } else if (a[la] == b[rb]) {
            la++;
            rb--;
        }
        // cout << la << " " << ra << " | " << lb << " " << rb << endl; 
    }
    cout << "Bob" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}