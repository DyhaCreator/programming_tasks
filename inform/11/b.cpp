#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    int n = a.size();
    vector<pair<int, int>> dp(n);
    int mx0 = 0;
    pair<int, int> mxP = {0, 0};
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') {
            dp[i] = {mx0 + 1, 0};
            mx0++;
        } else if (a[i] == '1') {
            dp[i] = {mxP.F, mxP.S + 1};
            mxP.S++;
            if (dp[i].F + dp[i].S < mx0 + 1) {
                dp[i] = {mx0, 1};
                mxP = dp[i];
            }
        }
    }
    pair<int, int> mx = {0, 0};
    for (auto &x : dp) {
        if (x.F + x.S > mx.F + mx.S) {
            mx = x;
        }
    }
    for (int i = 0; i < mx.F; i++) cout << 0;
    for (int i = 0; i < mx.S; i++) cout << 1;
    cout << endl;
    return 0;
}