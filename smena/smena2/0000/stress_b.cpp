#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool f2(vector<int> &a, vector<int> &b, int c) {
    if (a.size() < b.size() + 1)
        return 1;
    if (a.size() == b.size() + 1) {
        for (int i = 0; i < a.size(); i++) {
            if (i == b.size()) {
                if (a[i] < c) {
                    return 1;
                } else if (a[i] > c) {
                    return 0;
                }
            } else {
                if (a[i] < b[i]) {
                    return 1;
                } else if (a[i] > b[i]) {
                    return 0;
                }
            }
        }
    }
    return 0;
}

int solve2(string s) {
    int n = 3;
    vector<int> a = {};
    for (auto &x : s)
        a.push_back(x - '0');
    vector<vector<int>> last_dp(3);
    vector<vector<int>> th_dp(3);
    if (a[0] != 0) last_dp[a[0] % 3].push_back(a[0]);
    /*for (auto &x : last_dp) {
        if (x.size() == 0) cout << -1 << " ";
        else {for (auto &y : x)
            cout << y;
        cout << " ";}
    }
    cout << endl;*/
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            th_dp = last_dp;
            if (th_dp[0].size() > 0)
                th_dp[0].push_back(a[i]);
            if (th_dp[1].size() > 0)
                th_dp[1].push_back(a[i]);
            if (th_dp[2].size() > 0)
                th_dp[2].push_back(a[i]);
        } else if (a[i] % 3 == 0) {
            th_dp = last_dp;
            th_dp[0].push_back(a[i]);
            if (th_dp[1].size() != 0)
                th_dp[1].push_back(a[i]);
            if (th_dp[2].size() != 0)
                th_dp[2].push_back(a[i]);
        } else if (a[i] % 3 == 1) {
            th_dp = last_dp;
            if (last_dp[2].size() != 0 && f2(th_dp[0], last_dp[2], a[i])) {
                th_dp[0] = last_dp[2];
                th_dp[0].push_back(a[i]);
            }
            if (f2(th_dp[1], last_dp[0], a[i])) {
                th_dp[1] = last_dp[0];
                th_dp[1].push_back(a[i]);
            }
            if (last_dp[1].size() != 0 && f2(th_dp[2], last_dp[1], a[i])) {
                th_dp[2] = last_dp[1];
                th_dp[2].push_back(a[i]);
            }
        } else if (a[i] % 3 == 2) {
            th_dp = last_dp;
            if (last_dp[1].size() != 0 && f2(th_dp[0], last_dp[1], a[i])) {
                th_dp[0] = last_dp[1];
                th_dp[0].push_back(a[i]);
            }
            if (last_dp[2].size() != 0 && f2(th_dp[1], last_dp[2], a[i])) {
                th_dp[1] = last_dp[2];
                th_dp[1].push_back(a[i]);
            }
            if (f2(th_dp[2], last_dp[0], a[i])) {
                th_dp[2] = last_dp[0];
                th_dp[2].push_back(a[i]);
            }
        }
        /*for (auto &x : th_dp) {
            if (x.size() == 0) cout << -1 << " ";
            else {for (auto &y : x)
                cout << y;
            cout << " ";}
        }
        cout << endl;*/
        last_dp = th_dp;
    }
    if (th_dp[0].size() == 0 && n > 1) {
        cout << 0 << endl;
        return 0;
    } else if (th_dp[0].size() == 0) {
        cout << a[0] << endl;
        return 0;
    }
    for (auto &x : th_dp[0])
        cout << x;
    cout << endl;
    return 0;
}


bool f(vector<int> &a, vector<int> &b, int c) {
    if (a.size() < b.size() + 1)
        return 1;
    if (a.size() == b.size() + 1) {
        for (int i = 0; i < a.size(); i++) {
            if (i == a.size() - 1 && a[i] < c) {
                return 1;
            } else if (a[i] < b[i]) {
                return 1;
            }
        }
    }
    return 0;
}

int solve1(string s) {
    int n = 3;
    vector<int> a = {};
    for (auto &x : s)
        a.push_back(x - '0');
    vector<vector<int>> last_dp(3);
    vector<vector<int>> th_dp(3);
    last_dp[a[0] % 3].push_back(a[0]);
    /*for (auto &x : last_dp) {
        if (x.size() == 0) cout << -1 << " ";
        else {for (auto &y : x)
            cout << y;
        cout << " ";}
    }
    cout << endl;*/
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            th_dp = last_dp;
            if (th_dp[0].size() > 0)
                th_dp[0].push_back(a[i]);
            if (th_dp[1].size() > 0)
                th_dp[1].push_back(a[i]);
            if (th_dp[2].size() > 0)
                th_dp[2].push_back(a[i]);
        } else if (a[i] % 3 == 0) {
            th_dp = last_dp;
            th_dp[0].push_back(a[i]);
            if (th_dp[1].size() != 0)
                th_dp[1].push_back(a[i]);
            if (th_dp[2].size() != 0)
                th_dp[2].push_back(a[i]);
        } else if (a[i] % 3 == 1) {
            th_dp = last_dp;
            if (last_dp[2].size() != 0 && f(th_dp[0], last_dp[2], a[i])) {
                th_dp[0] = last_dp[2];
                th_dp[0].push_back(a[i]);
            }
            if (f(th_dp[1], last_dp[0], a[i])) {
                th_dp[1] = last_dp[0];
                th_dp[1].push_back(a[i]);
            }
            if (last_dp[1].size() != 0 && f(th_dp[2], last_dp[1], a[i])) {
                th_dp[2] = last_dp[1];
                th_dp[2].push_back(a[i]);
            }
        } else if (a[i] % 3 == 2) {
            th_dp = last_dp;
            if (last_dp[1].size() != 0 && f(th_dp[0], last_dp[1], a[i])) {
                th_dp[0] = last_dp[1];
                th_dp[0].push_back(a[i]);
            }
            if (last_dp[2].size() != 0 && f(th_dp[1], last_dp[2], a[i])) {
                th_dp[1] = last_dp[2];
                th_dp[1].push_back(a[i]);
            }
            if (f(th_dp[2], last_dp[0], a[i])) {
                th_dp[2] = last_dp[0];
                th_dp[2].push_back(a[i]);
            }
        }
        /*for (auto &x : th_dp) {
            if (x.size() == 0) cout << -1 << " ";
            else {for (auto &y : x)
                cout << y;
            cout << " ";}
        }
        cout << endl;*/
        last_dp = th_dp;
    }
    if (th_dp[0].size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (auto &x : th_dp[0])
        cout << x;
    cout << endl;
    return 0;
}

int main() {
    for (int j = 1; j < 10; j++) {
        for (int k = 0; k < 10; k++) {
            int i = j * 100 + k;
            cout << -i << endl;
            string s = to_string(i);
            solve1(s);
            solve2(s);
        }
    }
    /*for (int i = 100; i < 300; i++) {
        string s = to_string(i);
        if ((i >= 110 && i <= 119) || i == 141 || i == 144 || i == 171 || i == 174 || i == 177 || (i >= 220 && i <= 229) || i == 252 || i == 255 || i == 282 || i == 285 || i == 288) continue;
        cout << -i << endl;
        solve1(s);
        solve2(s);
    }*/
    return 0;
}