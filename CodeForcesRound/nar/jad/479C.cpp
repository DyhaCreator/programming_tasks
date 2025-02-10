#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>>  a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    sort(a.begin(), a.end());
    int last = min(a[0].F, a[0].S);
    for (int i = 1; i < n; i++) {
        if (last <= a[i].S)
            last = a[i].S;
        else
            last = a[i].F;
    }
    cout << last << endl;
    return 0;
}