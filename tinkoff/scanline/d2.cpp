#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct line{
    int l, r;
    line() {}
    line(int l, int r) {
        this->l = l;
        this->r = r;
    }
};

int main() {
    ll n;
    cin >> n;
    vector<line>lines = vector<line>(n);
    for (auto &x : lines)
        cin >> x.l >> x.r;
    vector<ll>ans = vector<ll>(n);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (i != j) {
                if (lines[i].l >= lines[j].l && lines[i].r <= lines[j].r) {
                    ans[i] = j + 1;
                    break;
                }
            }
        }
    }
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}