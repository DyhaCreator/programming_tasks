#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int dist(pair<int, int> &a, pair<int, int> &b) {
    return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    int s, f;
    cin >> s >> f;
    s--;f--;
    vector<int> d(n, INF);
    vector<int> used(n);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int num = -1;
        for (int j = 0; j < n; j++) {
            if (used[j] == 0 && (num == -1 || d[num] > d[j])) {
                num = j;
            }
        }
        used[num] = 1;
        for (int j = 0; j < n; j++) {
            if (used[j] == 0 && d[j] > d[num] + dist(a[j], a[num])) {
                d[j] = d[num] + dist(a[j], a[num]);
            }
        }
    }
    cout << d[f] << endl;
    return 0;
}