#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2{
    ll x = 0;
    ll y = 0;
    int2() {}
    int2(ll x, ll y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    ll n;
    cin >> n;
    vector<ll>a = vector<ll>(n);
    for (auto &x : a)
        cin >> x;
    vector<int2>p = vector<int2>();
    p.push_back(int2(1, a[0]));
    for (int i = 1; i < n; i++) {
        if (a[i] == p.back().y) {
            p[p.size() - 1].x++;
        } else {
            p.push_back(int2(1, a[i]));
        }
    }
    /*for (auto x : p)
        cout << x.x << " ";
    cout << endl;
    for (auto x : p)
        cout << x.y << " ";
    cout << endl;*/
    ll max = -1;
    for (int i = 1; i < p.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (p[i].y == p[j].y && p[i].x + p[j].x > max) {
                max = p[i].x + p[j].x;
            }
        }
    }
    for (int i = 0; i < p.size(); i++) {
        if (p[i].x > max) {
            max = p[i].x;
        } 
    }
    cout << max << endl;
    return 0;
}