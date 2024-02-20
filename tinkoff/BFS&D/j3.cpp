#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000007
#define ll long long
using namespace std;

int f(string str, int k) {
    int ans = 0;
    for (auto &x : str) {
        ans = (ans * 10 + x - '0') % k;
    }
    // cout << ans << endl;
    return ans;
}

int main() {
    // cout << f("10201", 101) << endl;
    string str;
    int k;
    cin >> str;
    cin >> k;
    int m;
    cin >> m;
    vector<int> a(m);
    for (auto &x : a)
        cin >> x;

    queue<pair<string, ll>> q;
    q.push({str, 0});

    while (!q.empty()) {
        string num = q.front().first;
        // cout << num << endl;
        int lay = q.front().second;
        q.pop();

        if (f(num, k) == 0) {
            cout << num << endl;
            return 0;
        }

        if (lay == 5) {
            cout << -1 << endl;
            return 0;
        }



        for (auto &x : a) {
            q.push({num + char(x + '0'), lay + 1});
        }
    }
    return 0;
}