#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = INF;
    for (int t = 0; t < n - 1; t++) {
        vector<int> a = {};
        for (int j = 0; j < n; j++) {
            if (j != t && j != t + 1) {
                //cout << s[j] << " ";
                a.push_back(s[j] - '0');
            } else if (j != t + 1) {
                // cout << (s[j] - '0') * 10 + (s[j + 1] - '0') << " ";
                a.push_back((s[j] - '0') * 10 + (s[j + 1] - '0'));
            }
        }
        /*for (auto &x : a)
            cout << x << " ";
        cout << endl;*/
        vector<int> b = {};
        int one = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == 0) {
                cout << 0 << endl;
                return;
            }
            if (a[i] != 1)
                b.push_back(a[i]);
            else one++;
        }
        /*for (auto &x : b)
            cout << x << " ";
        cout << endl;*/
        int lans = 0;
        for (auto &x : b)
            lans += x;
        // cout << one << endl;
        if (lans == 0 && one > 0) lans = 1;
        // cout << lans << endl;
        ans = min(ans, lans);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}