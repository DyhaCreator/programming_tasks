#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct s{
    int x1, y1, x2, y2;
    s() {};
    s(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
};

ll ss(s a) {
    return abs(a.x2 - a.x1) * abs(a.y2 - a.y1);
}

s f(s a, s b) {
    if (a.x1 == -INF) return a;
    if (a.x1 > b.x2 || a.x2 < b.x1 || a.y1 > b.y2 || a.y2 < b.y1)
        return s(-INF, -INF, -INF, -INF);
    s c = s(0, 0, 0, 0);
    c.x1 = max(a.x1, b.x1);
    c.y1 = max(a.y1, b.y1);
    c.x2 = min(a.x2, b.x2);
    c.y2 = min(a.y2, b.y2);
    return c;
}

int main() {
    int n;
    cin >> n;
    vector<s> a(n);
    for (auto &x : a)
        cin >> x.x1 >> x.y1 >> x.x2 >> x.y2;
    vector<s> pref(n + 1);
    vector<s> suff(n + 1);
    pref[0] = s(-INF + 7, -INF, INF, INF);
    suff[n] = s(-INF + 7, -INF, INF, INF);
    for (int i = 0; i < n; i++)
        pref[i + 1] = f(pref[i], a[i]);
    for (int i = n - 1; i >= 0; i--)
        suff[i] = f(suff[i + 1], a[i]);
    for (int i = 0; i < n; i++) {
        s c = f(pref[i], suff[i + 1]);
        if (c.x1 != -INF) {
            cout << c.x1 << " " << c.y1 << endl;
            return 0;
        }
    }
    return 0;
}