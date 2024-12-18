#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> mp(26);
    for (auto &x : str)
        mp[x - 65]++;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (mp[i] >= i + 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}