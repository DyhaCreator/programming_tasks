#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f(string &a, int k) {
    int ans = 0;
    for (auto &x : a)
        ans = (ans * 10 + x - '0') % k;
    return ans;
}

int main() {
    string a;
    int k;
    cin >> a >> k;
    int n;
    cin >> n;
    vector<ll> d(n);
    for (auto &x : d)
        cin >> x;
    sort(d.begin(), d.end());
    vector<int> used(k);
    vector<string> pref(k);
    queue<int> q;
    q.push(f(a, k));
    used[f(a, k)] = 1;
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        for (auto &x : d) {
            if (used[(num * 10 + x) % k] == 0) {
                q.push((num * 10 + x) % k);
                pref[(num * 10 + x) % k] = pref[num];
                pref[(num * 10 + x) % k].push_back(x + '0');
                used[(num * 10 + x) % k] = used[num] + 1;
            }
        }
    }
    /*for (auto &x : pref)
        cout << ((x == "")?"x":x) << " ";
    cout << endl;*/
    if (used[0] == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << a << pref[0] << endl;
    return 0;
}