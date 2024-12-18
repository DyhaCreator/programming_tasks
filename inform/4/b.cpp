#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int ans = INF;

void gen(string &s, int k, int num) {
    // cout << num << endl;
    if (num >= k) {
        int save = num;
        vector<int> a = {};
        while (save > 0) {
            a.push_back(save % 10);
            save /= 10;
        }
        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i] == a[i + 1]) {
                return;
            }
        }
        // cout << num << endl;
        ans = min(ans, num);
        return;
    }
    // cout << num << endl;
    for (auto &x : s) {
        if (num == 0 && x == '0') continue;
        num = num * 10 + x - '0';
        gen(s, k, num);
        num /= 10;
    }
}

int main() {
    string s;
    getline(cin, s);
    int k;
    cin >> k;
    if (s[0] == '0' || s.size() <= 1) {cout << -1 << endl;}
    else {
        gen(s, k, 0);
        cout << ans << endl;
        return 0;
    }
    return 0;
}