#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tree(n * 2);
    for (int i = n; i < n * 2; i++)
        cin >> tree[i];
    for (int i = n * 2 - 1; i > 1; i -= 2)
        tree[i / 2] = max(tree[i], tree[i - 1]);

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

        int ans = -INF;
        while (l <= r) {
            if (l % 2 != 0) ans = max(ans, tree[l]);
            if (r % 2 == 0) ans = max(ans, tree[r]);
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}