#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> b(n);
    for (int i = 1; i < n; i++) {
        b[i] = b[i - 1];
        if (a[i] - a[i - 1] > 0)
            b[i]++;

        //cout << a[i] - a[i - 1] << " ";
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        cout << b[r] - b[l] << endl;
    }
    return 0;
}