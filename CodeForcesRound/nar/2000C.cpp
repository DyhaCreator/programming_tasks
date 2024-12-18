#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const ll INF = 1e18 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string str;
        cin >> str;
        if (str.size() != n) {
            cout << "NO" << endl;
            continue;
        }
        vector<ll> count(27, -INF);
        map<ll, char> mp;
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (count[str[j] - 'a'] == -INF && mp[a[j]] == 0) {
                count[str[j] - 'a'] = a[j];
                mp[a[j]] = str[j];
            } else if (count[str[j] - 'a'] == a[j] && mp[a[j]] == str[j]) {
                
            } else {
                found = 1;
            }
        }
        cout << ((found)?"NO":"YES") << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}