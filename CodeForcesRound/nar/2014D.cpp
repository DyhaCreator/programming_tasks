#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct w{
    int l, r;
    w() {}
    w(int l, int r) {
        this->l = l;
        this->r = r;
    }
};

bool comp1(w &a, w &b) {
    if (a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}

bool comp2(const w &a, const w &b) {
    if (a.r == b.r) return a.l < b.l;
    return a.r < b.r;
}

void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<w> work(k);
    for (auto &x : work)
        cin >> x.l >> x.r;
    sort(work.begin(), work.end(), comp1);
    set<w, decltype(&comp2)> st(&comp2);
    int index = 0;
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; i++) {
        while (index < k && work[index].l <= i) {
            st.insert(work[index]);
            index++;
        }
        while (!st.empty() && st.begin()->r <= i - d)
            st.erase(*st.begin());
        ans[i] = st.size();
    }
    int mx = d;
    int mn = d;
    for (int i = d; i <= n; i++) {
        if (ans[mx] < ans[i]) mx = i;
        if (ans[mn] > ans[i]) mn = i;
    }
    cout << mx - d + 1 << " " << mn - d + 1 << endl;
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}