#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000007
using namespace std;

int f(string num, int k, int ost) {
    int ans = (ost * 10 + (num.back() - '0')) % k;
    return ans;
}

int f2(string &num, int k) {
    int ans = 0;
    for (auto &x : num) {
        ans = (ans * 10 + (x - '0')) % k;
    }
    return ans;
}

int main() {
    string num;
    int k;
    cin >> num >> k;
    int n;
    cin >> n;
    vector<int> d(n);
    for (auto &x : d)
        cin >> x;
    
    sort(d.begin(), d.end());

    queue<pair<string, pair<int, int>>> q;
    q.push({num, {0, f2(num, k)}});

    while (!q.empty()) {
        string index = q.front().first;
        // cout << index << endl;
        int layer = q.front().second.first;
        int ost = q.front().second.second;
        if (layer == 7) {
            cout << -1 << endl;
            return 0;
        }
        if (ost == 0) {
            cout << index << endl;
            return 0;
        }
        q.pop();

        for (auto &x : d) {
            q.push({index + char(x + '0'), {layer + 1, f(index + char(x + '0'), k, ost)}});
        }
    }

    return 0;
}