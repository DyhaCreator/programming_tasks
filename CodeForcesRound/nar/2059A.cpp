#include <algorithm>
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
    vector<int> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    set<int> sta;
    set<int> stb;
    for (auto &x : a)
        sta.insert(x);
    for (auto &x : b)
        stb.insert(x);
    set<int> st;
    for (auto &x : sta) {
        for (auto &y : stb) {
            st.insert(x + y);
            if (st.size() >= 3) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}