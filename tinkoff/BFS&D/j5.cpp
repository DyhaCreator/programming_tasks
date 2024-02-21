#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000007
#define prvec(vec) for(auto &x:vec)cout<<x<<" ";cout<<endl;
#define all(vec) vec.begin(),vec.end()
using namespace std;

int f(string num, int k) {
    int ans = 0;
    for (auto &x : num) {
        ans = (ans * 10 + x - '0') % k;
    }
    return ans;
}

int main() {
    string str;
    int k;
    cin >> str >> k;
    int m;
    cin >> m;
    vector<int> dig(m);
    for (auto &x : dig)
        cin >> x;
    sort(all(dig));
    int ost = f(str, k);

    vector<vector<int>> g(k);
    for (int i = 0; i < k; i++) {
        for (auto &x : dig) {
            int ost2 = (i * 10 + x) % k;
            g[ost2].push_back(i);
        }
    }

    // prvec(g[0]);

    queue<int> q;
    q.push(0);
    vector<int> used(k, INF);
    vector<int> prev(k, -1);
    vector<int> prevx(k, -1);
    used[0] = 0;
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        for (int i = 0; i < g[index].size(); i++) {
            int x = g[index][i];
            if (used[x] == INF) {
                used[x] = used[index] + 1;
                prev[x] = index;
                prevx[x] = dig[i];
                q.push(x);
            }
        }
    }

    if (used[ost] == INF) {
        cout << -1 << endl;
        return 0;
    }

    // cout << used[ost] << endl;
    /*prvec(used);
    prvec(prev);
    prvec(prevx);*/
    
    vector<int> ans = {};
    int p = ost;
    while (p != -1) {
        ans.push_back(prevx[p]);
        p = prev[p];
    }
    cout << str;
    // reverse(all(ans));
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}