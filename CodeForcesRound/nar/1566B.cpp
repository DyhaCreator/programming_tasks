#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int sum = 0;
    for (auto &x : s)
        sum += x - '0';
    int start = 0;
    while (start < s.size() && s[start] != '0') start++;
    if (start == s.size()) {
        cout << 0 << endl;
        return;
    }
    while (start < s.size() && s[start] != '1') start++;
    if (start == s.size()) {
        cout << 1 << endl;
        return;
    }
    while (start < s.size() && s[start] != '0') start++;
    if (start != s.size()) {
        cout << 2 << endl;
        return;
    }
    cout << 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}