#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int nod(int a, int b) {
    if (a == 1 || b == 1) return 1;
    if (a == 0 || b == 0) return 0;
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    int n;
    cin >> n;

    vector<ll> vec(n, 1);
    for (auto &x : vec)
        cin >> x;

    ll ct = 0;
    while ((1 << ct) < n)
        ct++;
    n = 1 << ct;

    while (vec.size() < n)
        vec.push_back(1);
    vector<ll> tree(n, 1);

    for (auto &x : vec)
        tree.push_back(x);

    for (int i = n * 2 - 1; i > 1; i -= 2)
        tree[i / 2] = nod(tree[i], tree[i - 1]);
    int q;
    cin >> q;


    for (int ii = 0; ii < q; ii++) {
        char com;
        cin >> com;
        if (com == 's') {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            l += n;
            r += n;
            // cout << l << " " << r << endl;

            ll ans = tree[l];
            while (l <= r) {
                if (l % 2 != 0) ans = nod(ans, tree[l]);
                if (r % 2 == 0) ans = nod(ans, tree[r]);
                l = (l + 1) / 2;
                r = (r - 1) / 2;
                // cout << l << " " << r << " " << sum << endl;
            }
            cout << ans << endl;
        } else {
            ll index, nx;
            cin >> index >> nx;
            index--;
            index += n;
            int newX = nx;

            while (index >= 1) {
                tree[index] = newX;
                if (index % 2 == 0) {
                    newX = nod(newX, tree[index + 1]);
                } else {
                    newX = nod(newX, tree[index - 1]);
                }
                index = index / 2;
            }
            /*for (auto &x : tree)
                cout << x << " ";
            cout << endl;*/
        }
    }
    return 0;
}