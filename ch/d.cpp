#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> k >> n;
    vector<vector<int>> a(k);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int t;
        char g;
        cin >> t >> g;
        if (g == 'F') {
            ans[i] = 0;
            continue;
        }
        a[t - 1].push_back(i);
    }
    /*for (auto &x : a) {
        for (auto &y : x) 
            cout << y << " ";
        cout << endl;
    }*/

    for (auto &x : a) {
        if (x.size() % 2 == 0 && x.size() > 0) {
            // cout << x.size() << " " << x[x.size() / 2] << endl;
            ans[x[x.size() / 2]] = 1;
            ans[x[x.size() / 2 - 1]] = 1;
        } else if (x.size() > 0) {
            ans[x[x.size() / 2]] = 1;
        }
    }

    for (auto &x : ans)
        cout << ((x)?"Yes":"No") << endl;

    return 0;
}