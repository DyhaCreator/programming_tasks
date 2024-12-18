#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> vec(n, 0);
    ll ct = 0;
    while ((1 << ct) < n)
        ct++;
    n = 1 << ct;
    while (vec.size() < n)
        vec.push_back(0);
    vector<ll> tree(n);
    for (auto &x : vec)
        tree.push_back(x);
    /*for (auto &x : tree)
        cout << x << " ";
    cout << endl;*/

    for (int i = n * 2 - 1; i > 1; i -= 2)
        tree[i / 2] = tree[i] + tree[i - 1];


    for (int ii = 0; ii < q; ii++) {
        char com;
        cin >> com;
        if (com == 'Q') {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            l += n;
            r += n;
            // cout << l << " " << r << endl;

            ll sum = 0;
            while (l <= r) {
                if (l % 2 != 0) sum += tree[l];
                if (r % 2 == 0) sum += tree[r];
                l = (l + 1) / 2;
                r = (r - 1) / 2;
                // cout << l << " " << r << " " << sum << endl;
            }
            cout << sum << endl;
        } else {
            ll index, nx;
            cin >> index >> nx;
            index--;
            index += n;
            ll del = nx - tree[index];

            while (index >= 1) {
                tree[index] += del;
                index = index / 2;
            }
        }
    }
    return 0;
}