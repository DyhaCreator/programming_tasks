#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    string num;
    cin >> num;
    string sn = num;
    sort(sn.begin(), sn.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int count = 0;
        for (int j = 0; j < l; j++) {
            if (num[j] != s[j]) {
                count++;
            }
        }
        sort(s.begin(), s.end());
        if (count <= k && s == sn) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}