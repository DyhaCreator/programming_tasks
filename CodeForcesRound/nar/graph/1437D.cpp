#include <algorithm>
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
    vector<int> b = {};
    int cnt = 1;
    for (int i = 2; i < n; i++) {
        if (a[i - 1] < a[i]) {
            cnt++;
        } else {
            b.push_back(cnt);
            cnt = 1;
        }
    }
    b.push_back(cnt);
    vector<int> pref(b.size() + 1);
    for (int i = 0; i < b.size(); i++)
        pref[i + 1] = pref[i] + b[i];
    
    vector<int> c = {1};
    int index = 0;
    while (index < b.size()) {
        c.push_back(pref[min(index + c.back(), int(b.size()))] - pref[index]);
        index += c[c.size() - 2];
    }
    
    cout << c.size() - 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}