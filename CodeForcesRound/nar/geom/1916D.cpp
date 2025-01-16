#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<vector<string>> ans(50);

void solve() {
    int n;
    cin >> n;
    for (auto &x : ans[n / 2])
        cout << x << endl;
}

int main() {
    ans[0].push_back("1");
    ans[1].push_back("169");
    ans[1].push_back("196");
    ans[1].push_back("961");
    for (int i = 2; i < 50; i++) {
        for (auto &x : ans[i - 1])
            ans[i].push_back(x + "00");

        string a = "1";
        for (int j = 0; j <= i - 2; j++)
            a.push_back('0');
        a.push_back('6');
        for (int j = 0; j <= i - 2; j++)
            a.push_back('0');
        a.push_back('9');
        ans[i].push_back(a);

        a = "9";
        for (int j = 0; j <= i - 2; j++)
            a.push_back('0');
        a.push_back('6');
        for (int j = 0; j <= i - 2; j++)
            a.push_back('0');
        a.push_back('1');
        ans[i].push_back(a);
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}