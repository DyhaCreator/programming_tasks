#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct quest{
    ll l, r, d;
    quest() {}
    quest(int l, int r, int d) {
        this->l = l;
        this->r = r;
        this->d = d;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<quest> q(m);
    for (auto &x : q)
        cin >> x.l >> x.r >> x.d;
    vector<int> for_quest(m + 1);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        for_quest[l - 1] += 1;
        for_quest[r] -= 1;
    }
    /*for (auto &x : for_quest)
        cout << x << " ";
    cout << endl;*/
    vector<int> for_quest2(m + 1);
    for (int i = 1; i <= m; i++) {
        for_quest2[i] = for_quest2[i - 1] + for_quest[i - 1];
    }
    /*for (auto &x : for_quest2)
        cout << x << " ";
    cout << endl;*/
    vector<ll> dig(n + 1);
    for (int i = 0; i < m; i++) {
        dig[q[i].l - 1] += q[i].d * for_quest2[i + 1];
        dig[q[i].r] -= q[i].d * for_quest2[i + 1];
    }
    /*for (auto &x : dig)
        cout << x << " ";
    cout << endl;*/
    vector<ll> ans(n + 1);
    for (int i = 1; i <= n; i++)
        ans[i] = ans[i - 1] + dig[i - 1];
    for (int i = 0; i < n; i++) {
        cout << ans[i + 1] + a[i] << " ";
    }
    cout << endl;
    return 0;
}