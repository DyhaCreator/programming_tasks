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
    vector<string> g(n);
    for (auto &x : g)
        cin >> x;
    pair<ll, ll> u = {0, 0};
    pair<ll, ll> l = {0, 0};
    pair<ll, ll> d = {0, 0};
    pair<ll, ll> r = {0, 0};
    for (auto &x : g) {
        if (x == "UL") {
            u.F++;
            l.S--;
            d.S--;
            r.F++;
        } else if (x == "UR") {
            u.F++;
            l.F++;
            d.S++;
            r.S++;
        } else if (x == "DL") {
            u.S--;
            l.S--;
            d.F--;
            r.F--;
        } else if (x == "DR") {
            u.S++;
            l.F--;
            d.F--;
            r.S++;
        } else if (x == "ULDR") {
            u.F++;
            l.S--;
            d.F--;
            r.S++;
        }
    }
    cout << (r.S - d.S + 1) * (r.S - u.S + 1) << endl;
    /*cout << u.F << " " << u.S << endl;
    cout << l.F << " " << l.S << endl;
    cout << d.F << " " << d.S << endl;
    cout << r.F << " " << r.S << endl;*/
    
    return 0;
}