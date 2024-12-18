#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> ans = {};
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < 4; j++)
            if (str[j] == '#')
                ans.push_back(j + 1);
    }
    reverse(ans.begin(), ans.end());
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