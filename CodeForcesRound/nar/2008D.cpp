#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int color = 0;

int dfs(int index, vector<int> &a, vector<int> &used) {
    used[index] = color;
    if (used[a[index] - 1] == 0)
        dfs(a[index] - 1, a, used);
    return 0;
}

void solve() {
    color = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    string b;
    cin >> b;
    vector<int> used(n, 0);
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            color++;
            dfs(i, a, used);
        }
    }
    vector<int> count(color, 0);
    for (int i = 0; i < n; i++)
        if (b[i] == '0') count[used[i] - 1]++;
    for (int i = 0; i < n; i++)
        cout << count[used[i] - 1] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}