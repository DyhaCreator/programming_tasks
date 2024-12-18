#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> count(610001);
    for (auto &x : a)
        count[x]++;
    vector<int> pref(610002);
    for (int i = 0; i < 610001; i++)
        pref[i + 1] = pref[i] + count[i];
    int q;
    cin >> q;
    map<int, int> mp;
    for (int i = 0; i < q; i++) {
        int l;
        cin >> l;
        if (mp[l] != 0) {
            cout << mp[l] << endl;
            continue;
        }
        int ans = 0;
        for (int j = 1; j * l <= 610001; j++) {
            ans = max(ans, pref[j * l] - pref[(j - 1) * l]);
            // cout << pref[j * l] - pref[(j - 1) * l] << " ";
        }
        cout << ans << " ";
        mp[l] = ans;
    }
    cout << endl;
    return 0;
}