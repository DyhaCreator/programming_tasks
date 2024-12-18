#include <algorithm>
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
    int ct = 0;
    while ((1 << ct) < n)
        ct++;
    n = (1 << ct);
    while (vec.size() < n)
        vec.push_back(1);

    vector<vector<int>> tree(n * 2, vector<int>());

    for (int i = 0; i < n; i++) {
        if (vec[i] == 0) {
            tree[i + n] = {i};
        }
    }
    
    for (int i = n * 2 - 1; i > 1; i -= 2) {
        vector<int> nn = {};
        for (auto &x : tree[i])
            nn.push_back(x);
        for (auto &x : tree[i - 1])
            nn.push_back(x);
        tree[i / 2] = nn;
    }

    /*for (auto &x : tree) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char com;
        cin >> com;
        if (com == 's') {
            int l, r, k;
            cin >> l >> r >> k;
            k--;
            l--;
            r--;
            l += n;
            r += n;
            
            vector<int> ans = {};
            while (l <= r) {
                if (l % 2 != 0) {
                    for (auto &x : tree[l])
                        ans.push_back(x);
                }
                if (r % 2 == 0) {
                    for (auto &x : tree[r])
                        ans.push_back(x);
                }
                l = (l + 1) / 2;
                r = (r - 1) / 2;
            }

            sort(ans.begin(), ans.end());
            if (k < ans.size()) {
                cout << ans[k] + 1 << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            int index, x;
            cin >> index >> x;
            index--;
            // cout << index << endl;
            if ((vec[index] == 0 && x != 0) || (vec[index] != 0 && x == 0)) {
                vec[index] = x;
                if (x != 0) {
                    tree[index + n] = {};
                } else {
                    tree[index + n] = {index};
                }

                /*for (auto &x : tree[index + n])
                    cout << x << " ";
                cout << endl;*/

                index += n;

                while (index > 1) {
                    index = index / 2;

                    vector<int> nn = {};
                    for (auto &x : tree[index * 2]) {
                        nn.push_back(x);
                    }
                    for (auto &x : tree[index * 2 + 1]) {
                        nn.push_back(x);
                    }
                    tree[index] = nn;
                }

                /*for (auto &x : tree) {
                    for (auto &y : x)
                        cout << y << " ";
                    cout << endl;
                }*/
            }
        }
    }
    return 0;
}