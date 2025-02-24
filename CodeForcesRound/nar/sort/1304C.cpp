#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct int3{
    int t, l, h;
    int3() {}
    int3(int t, int l, int h) {
        this->t = t;
        this->l = l;
        this->h = h;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int3> a(n);
    for (auto &x : a)
        cin >> x.t >> x.l >> x.h;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}