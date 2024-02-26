#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &x : vec)
        cin >> x;
    vec.push_back(0);
    int ct = 0;
    while ((1 << ct) < n) 
        ct++;
    vector<int> tree((1 << ct) * 2, n);
    int base = n;
    for (int i = 0; i < n; i++) {
        tree[i + (1 << ct)] = i;
    }
    n = (1 << ct);
    for (int i = n * 2 - 1; i > 1; i -= 2) {
        if (vec[tree[i]] > vec[tree[i - 1]]) {
            tree[i / 2] = tree[i];
        } else {
            tree[i / 2] = tree[i - 1];
        }
    }

    /*for (auto &x : tree)
        cout << x << " ";
    cout << endl;*/

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l += n - 1;
        r += n - 1;

        // cout << l << " " << r << endl;

        int ans = base;
        while (l <= r) {
            if (l % 2 != 0 && vec[tree[l]] >= vec[ans]) ans = tree[l];
            if (r % 2 == 0 && vec[tree[r]] >= vec[ans]) ans = tree[r];
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        cout << ans + 1 << endl;
    }
    return 0;
}