#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> ans = {};
    int found = 0;
    for (int i = 0; i <= 40; i++) {
        set<int> st;
        for (auto &x : a)
            st.insert(x);
        ll sum = 0;
        for (auto &x : st)
            sum += x;
        if (st.size() == 1 && *st.begin() == 0) {
            found = 1;
            break;
        }
        int m = sum / st.size();
        ans.push_back(m);
        for (auto &x : a)
            x = abs(x - m);
        /*for (auto &x : a)
            cout << x << " ";
        cout << endl;*/
    }
    if (!found) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}