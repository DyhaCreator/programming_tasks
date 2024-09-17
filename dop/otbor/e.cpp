#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int solve() {
    int n;
    cin >> n;
    map<ll, ll> mp;
    set<ll> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 2048) {
            st.insert(x);
            mp[x]++;
        }
        if (x == 2048) {
            cout << "YES" << endl;
            return 0;
        }
    }
    /*for (auto &x : st)
        cout << x << " " << mp[x] << endl;*/
    bool find = 0;
    int ch = 1;
    while (ch > 0) {
        set<ll> st2;
        map<ll, ll> mp2;
        ch = 0;
        for (auto &x : st) {
            if (mp[x] >= 2) {
                st2.insert(x * 2);
                mp2[x * 2]++;
                ch++;
            } else {
                st2.insert(x);
                mp2[x]++;
            }
        }
        /*cout << ch << endl;
        for (auto &x : st2)
            cout << x << " " << mp2[x] << endl;
        cout << endl;*/
        if (st2.find(2048) != st2.end()) {
            cout << "YES" << endl;
            find = 1;
            break;
        }
        st = st2;
        mp = mp2;
        // cout << ch << endl;
    }
    if (!find) cout << "NO" << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}