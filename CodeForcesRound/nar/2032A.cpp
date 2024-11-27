#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (auto &x : a)
        cin >> x;
    int count = 0;
    for (auto &x : a)
        count += x;
    cout << count % 2 << " ";
    if (n >= count) {
        cout << count << endl;
    } else {
        cout << count - ((count - n) * 2) << endl;
    }
    
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}