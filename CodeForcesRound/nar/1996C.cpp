#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> prefa(n + 1, vector<int>(26));
    vector<vector<int>> prefb(n + 1, vector<int>(26));
    // cout << a << "\n" << b << endl;
    for (int i = 1; i <= n; i++) {
        prefa[i] = prefa[i - 1];
        prefa[i][a[i - 1] - 'a']++;
        /*for (auto &x : prefa[i])
            cout << x << " ";
        cout << endl;*/
        prefb[i] = prefb[i - 1];
        prefb[i][b[i - 1] - 'a']++;
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        vector<int> ca(26);
        vector<int> cb(26);
        int ans = 0;
        for (int i = 0; i < 26; i++)
            ans += abs((prefa[r][i] - prefa[l - 1][i]) - (prefb[r][i] - prefb[l - 1][i]));
        cout << ans / 2 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}