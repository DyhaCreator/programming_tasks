#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int t;
int start = INF;
int time1 = 0;
int time2 = INF;

int th_time_start = 0;


void rec(vector<vector<pair<int, int>>> &a, vector<int> &used, int time, vector<pair<int, int>> ans) {
   int sum = 0;
    for (auto &x : used) sum += x;
    if (sum == t) {
        int all_time = 0;
        for (auto &x : ans)
            all_time += a[x.F][x.S].S - a[x.F][x.S].F;
        int wait_time = 0;
        for (int i = 1; i < ans.size(); i++)
            wait_time += a[ans[i].F][ans[i].S].F - a[ans[i - 1].F][ans[i - 1].S].S;

        if (th_time_start < start) {
            start = th_time_start;
            time1 = all_time;
            time2 = wait_time;
        } else if (th_time_start == start && wait_time < time2) {
            time1 = all_time;
            time2 = wait_time;
        }
        return;
    }
    
    ans.push_back({0, 0});
    
    for (int i = 0; i < t; i++) {
        if (used[i] == 0) {
            int f = 0;
            for (int j = 0; j < a[i].size(); j++) {
                pair<int, int> x = a[i][j];
                if (x.F - time >= 5) {
                    f = 1;
                    used[i] = 1;
                    ans[ans.size() - 1] = {i, j};
                    rec(a, used, x.S, ans);
                    used[i] = 0;
                }
            }
            if (f == 0) return;
        }
    }
}

int main() {
    cin >> t;
    vector<vector<pair<int, int>>> a(t);
    for (auto &x : a) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int h1, m1, h2, m2;
            char ch;
            cin >> h1 >> ch >> m1 >> ch >> h2 >> ch >> m2;
            x.push_back({h1 * 60 + m1, h2 * 60 + m2});
        }
    }
    for (auto &x : a) sort(x.begin(), x.end());
    
    for (int i = 0; i < t; i++) {
        vector<int> used(t, 0);
        used[i] = 1;
        for (int j = 0; j < a[i].size(); j++) {
            int time = a[i][j].S;
            th_time_start = a[i][j].F;
            rec(a, used, time, {{i, j}});
        }
    }
    cout << start / 60 << ":" << start % 60 << endl;
    cout << time1 << endl;
    cout << time2 << endl;
    return 0;
}