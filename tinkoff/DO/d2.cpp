#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;

    int ct = 0;
    while ((1 << ct) < n)
        ct++;

    cout << "YES" << endl;
    
    vector<int> tree((1 << (ct + 1)), -1);
    vector<int> indexTree((1 << (ct + 1)), -1);
    for (int i = 0; i < n; i++) {
        cin >> tree[i + (1 << ct)];
        indexTree[i + (1 << ct)] = i;
    }

    /*for (auto &x : tree)
        cout << x << " ";
    cout << endl;
    for (auto &x : indexTree)
        cout << x << " ";
    cout << endl;*/

    n = 1 << ct;

    for (int i = 2 * n - 1; i > 1; i -= 2) {
        if (tree[i] > tree[i - 1]) {
            tree[i >> 1] = tree[i];
            indexTree[i >> 1] = indexTree[i];
        } else {
            tree[i >> 1] = tree[i - 1];
            indexTree[i >> 1] = indexTree[i - 1];
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        l += n;
        r += n;

        int ans = 0;
        int ansIndex = -1;
        while (l <= r) {
            if (l % 2 != 0) {
                if (tree[l] > ans) {
                    ans = tree[l];
                    ansIndex = indexTree[l];
                }
            }
            if (r % 2 == 0) {
                if (tree[r] > ans) {
                    ans = tree[r];
                    ansIndex = indexTree[r];
                }
            }
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        cout << ansIndex + 1 << endl;
    }

    return 0;
}