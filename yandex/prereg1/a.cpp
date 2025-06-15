#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

pair<vector<int>, vector<int>> f2(int a, int b, int c, int d) {
    return {{a + c, b + d, a + d, b + c},
            {max(b, d), max(a, c), max(b, c), max(a, d)}};
}

int f(vector<int> &a, vector<int> &b) {
    vector<int> c = f2(a[0], b[0], a[1], b[1]).F;
    vector<int> d = f2(a[0], b[0], a[1], b[1]).S;
    vector<int> ansa = {};
    vector<int> ansb = {};
    for (int i = 0; i < c.size(); i++) {
        vector<int> a1 = f2(a[2], b[2], c[i], d[i]).F;
        vector<int> b1 = f2(a[2], b[2], c[i], d[i]).S;
        for (auto &x : a1)
            ansa.push_back(x);
        for (auto &x : b1)
            ansb.push_back(x);
    }
    int mn = INF;
    for (int i = 0; i < ansa.size(); i++)
        mn = min(mn, ansa[i] * ansb[i]);
    return mn;
}

int main() {
    vector<int> a(3);
    vector<int> b(3);
    for (int i = 0; i < 3; i++)
        cin >> a[i] >> b[i];
    int mn = INF;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i != j && j != k && k != i) {
                    vector<int> a1(3);
                    vector<int> b1(3);
                    a1[0] = a[i];
                    b1[0] = b[i];
                    a1[1] = a[j];
                    b1[1] = b[j];
                    a1[2] = a[k];
                    b1[2] = b[k];
                    mn = min(mn, f(a1, b1));
                }
            }
        }
    }
    cout << mn << endl;
    return 0;
}