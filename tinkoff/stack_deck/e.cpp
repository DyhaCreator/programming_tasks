#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct deque{
    vector<ll>d;
    ll fr() {
        return d[0];
    }
    void frset(ll buffer) {
        d[0] = buffer;
    }
    ll back() {
        return d[d.size() - 1];
    }
    void frd() {
        d.erase(d.begin());
    }
    void backd(ll a) {
        d.push_back(a);
    }
};

int main() {
    deque d;
    deque count;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a == 1) {
            ll x, c;
            cin >> x >> c;
            d.backd(x);
            count.backd(c);
        } else if (a == 2) {
            ll c, ans = 0;
            cin >> c;
            while (c != 0) {
                if (count.fr() <= c) {
                    c -= count.fr();
                    ans += count.fr() * d.fr();
                    count.frd();
                    d.frd();
                } else if (count.fr() > c) {
                    count.frset(count.fr() - c);
                    ans += c * d.fr();
                    c = 0;
                }
            }
            cout << ans << endl; 
        }
    }
    return 0;
}