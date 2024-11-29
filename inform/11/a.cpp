#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
unordered_map<string, int> mp;
int sum = 0;
int ans = 0;
int n;

void rec(vector<string> &a, vector<int> &used, string num) {
    if (num.size() == sum) {
        // cout << num << endl;
        if (mp[num] == 0) {
            mp[num] = 1;
            ans++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            rec(a, used, num + a[i]);
            used[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> used(n);
    for (auto &x : a)
        sum += x.size();
    rec(a, used, "");
    cout << ans << endl;
    return 0;
}