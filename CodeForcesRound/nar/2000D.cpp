#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct int2{
    int l, r;
    int2() {}
    int2(int l, int r) {
        this->l = l;
        this->r = r;
    }
};




/*class Matrix{
private:
    int sx, sy;
    vector<vector<int>> data;
public:
    Matrix() {}
    Matrix(int sx, int sy) {
        this->sx = sx;
        this->sy = sy;
    }
    Matrix(int sx, int sy, vector<vector<int>> data) {
        this->sx = sx;
        this->sy = sy;
        this->data = data;
    }
};
*/




int get(string &str, vector<int2> &sol, int l, int r) {
    // cout << l << " " << r << endl;
    int indexL = l + 1;
    while (indexL < r && str[indexL] != 'L')
        indexL++;
    int indexR = r - 1;
    while (indexR > l && str[indexR] != 'R')
        indexR--;

    if (indexL < indexR)
        get(str, sol, indexL, indexR);
    if (l < r) sol.push_back(int2(l, r));
    // cout << indexL << " " << indexR << endl;
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    string str;
    cin >> str;
    vector<int2> sol = {};
    get(str, sol, -1, n);
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] += pref[i - 1] + a[i - 1];
    /*for (auto &x : pref)
        cout << x << " ";
    cout << endl;
    for (auto &x : sol)
        cout << x.l << " " << x.r << "\n";
    cout << endl;*/
    ll ans = 0;
    for (auto &x : sol) {
        // cout << pref[x.r + 1] << " " << pref[x.l] << endl;
        if (x.l != -1) ans += pref[x.r + 1] - pref[x.l];
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}