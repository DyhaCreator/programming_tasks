#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int solve() {
    int n;
    cin >> n;
    string str = "";
    string et = "aieou";
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[et[i % 5]]++;
    /*for (auto &x : et)
        cout << x << " " << mp[x] << endl;*/
    for (auto &x : et) {
        for (int i = 0; i < mp[x]; i++) {
            str.push_back(x);
        }
    }
    cout << str << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}