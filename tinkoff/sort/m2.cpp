#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define ss size()
using namespace std;

struct vec{
    ll x, y;
    vec() {}
    vec(ll x, ll y) {
        this->x = x;
        this->y = y;
    }
    vec(ll x1, ll y1, ll x2, ll y2) {
        this->x = x2 - x1;
        this->y = y2 - y1;
    }
};

ll cp(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

float S(vector<vec>v) {
    float s = 0.0;
    vec a = vec(v[0].x, v[0].y, v[1].x, v[1].y);
    for (int i = 2; i < v.ss; i++) {
        vec b = vec(v[0].x, v[0].y, v[i].x, v[i].y);
        s += (float)cp(b, a) / 2.0;
        a = b;
    }
    return abs(s);
}

struct s{
    ll n;
    float x;
    s() {}
    s(ll n, float x) {
        this->n = n;
        this->x = x;
    }
};

bool comp(s a, s b) {
    return a.x > b.x;
}

int main() {
    int n;
    cin >> n;
    vector<s>a = vector<s>();
    for (int i = 0; i < n; i++) {
        ll z;
        cin >> z;
        vector<vec>v = vector<vec>(z);
        for (int j = 0; j < z; j++) {
            ll x, y;
            cin >> x >> y;
            v[j].x = x;
            v[j].y = y;
        }
        s b = s(i, S(v));
        a.push_back(b);
    }
    sort(a.begin(), a.end(), comp);
    vector<int>ans = vector<int>(n);
    for (int i = 0; i < n; i++) {
        ans[a[i].n] = i;
    }
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
/*

3
3 -2 1 8 9 12 1
3 7 5 6 3 7 4
4 4 3 7 7 9 3 1 2

*/