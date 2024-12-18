#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &x : vec)
        cin >> x;
    ll ct = 0;
    while ((1 << ct) < n)
        ct++;
    for (int i = n; i < (1 << ct); i++) {
        vec.push_back(0);
    }
    n = 1 << ct;
    vector<int> tree(n * 2, -1);
    for (int i = 0; i < n; i++) {
        tree[i + n] = i;
    }
    // cout << -1 << endl;
    for (int i = 2 * n - 1; i > 1; i -= 2) {
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
        l--;
        r--;
        l += n;
        r += n;

        int ans = -1;
        while (l <= r) {
            if (l % 2 != 0) {
                // ans = max(ans, tree[l]);
                if (ans == -1 || vec[tree[l]] > vec[ans]) {
                    ans = tree[l];
                }
            }
            if (r % 2 == 0) {
                // ans = max(ans, tree[r]);
                if (ans == -1 || vec[tree[r]] > vec[ans]) {
                    ans = tree[r];
                }
            }
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        cout << ans + 1 << endl;
    }
    return 0;
}