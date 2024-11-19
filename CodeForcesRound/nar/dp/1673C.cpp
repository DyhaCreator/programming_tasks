#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f1(int n) {
    int ans = n;
    n /= 10;
    while (n > 0) {
        ans *= 10;
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int f2(int n) {
    int ans = n;
    while (n > 0) {
        ans *= 10;
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
int n = 40000;
vector<vector<int>> dp = {};
vector<vector<int>> pref = {};


void solve() {
    int num;
    cin >> num;
    vector<int> a = {};
    int ff = f1(1);
    for (int i = 2; ff <= num; i++) {
        a.push_back(ff);
        ff = f1(i);
    }
    ff = f2(1);
    for (int i = 2; ff <= num; i++) {
        a.push_back(ff);
        ff = f2(i);
    }
    sort(a.begin(), a.end());
    int m = a.size();
    /*for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    cout << pref[num][m] << endl;
}

int main() {
    vector<int> a = {};
    int ff = f1(1);
    for (int i = 2; ff <= n; i++) {
        a.push_back(ff);
        ff = f1(i);
    }
    ff = f2(1);
    for (int i = 2; ff <= n; i++) {
        a.push_back(ff);
        ff = f2(i);
    }
    sort(a.begin(), a.end());
    int m = a.size();
    dp = vector<vector<int>>(n + 1, vector<int>(m));
    pref = vector<vector<int>>(n + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    pref[0] = vector<int>(m + 1, 1);
    pref[0][0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= a[j]) dp[i][j] = pref[i - a[j]][j + 1];
            pref[i][j + 1] = (pref[i][j] + dp[i][j]) % 1000000007;
            ans++;
        }
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}