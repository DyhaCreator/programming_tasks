#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &x : vec) cin >> x;
    int ct = 0;
    while ((1 << ct) < n)
        ct++;
    n = (1 << ct);
    vector<int> tree(n, 0);
    for (auto &x : vec)
        tree.push_back(x);
    while (tree.size() < n * 2)
        tree.push_back(0);
    vector<int> countTree(n * 2, 1);  

    for (int i = n * 2 - 1; i > 1; i -= 2) {
        if (tree[i] > tree[i - 1]) {
            tree[i / 2] = tree[i];
            countTree[i / 2] = countTree[i];
        } else if (tree[i - 1] > tree[i]) {
            tree[i / 2] = tree[i - 1];
            countTree[i / 2] = countTree[i - 1];
        } else {
            tree[i / 2] = tree[i];
            countTree[i / 2] = countTree[i] + countTree[i - 1];
        }
    }

    /*for (auto &x : tree)  
        cout << x << " ";
    cout << endl;
    for (auto &x : countTree)
        cout << x << " ";
    cout << endl;*/

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char com;
        cin >> com;
        if (com == 'Q') {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            l += n;
            r += n;

            // cout << l << " " << r << endl;

            int ans = 0;
            int count = 0;
            while (l <= r) {
                if (l % 2 != 0) {
                    if (ans == tree[l]) {
                        count += countTree[l];
                    } else if (tree[l] > ans) {
                        ans = tree[l];
                        count = countTree[l];
                    }
                }
                if (r % 2 == 0) {
                    if (ans == tree[r]) {
                        count += countTree[r];
                    } else if (tree[r] > ans) {
                        ans = tree[r];
                        count = countTree[r];
                    }
                }
                l = (l + 1) / 2;
                r = (r - 1) / 2;
                // cout << l << " " << r << endl;
            }
            cout << count << " ";
        } else {
            int index, x;
            cin >> index >> x;

            index--;
            index += n;

            tree[index] = x;
            
            while (index > 1) {
                index = index / 2;
                if (tree[index * 2] > tree[index * 2 + 1]) {
                    tree[index] = tree[index * 2];
                    countTree[index] = countTree[index * 2];
                } else if (tree[index * 2] < tree[index * 2 + 1]) {
                    tree[index] = tree[index * 2 + 1];
                    countTree[index] = countTree[index * 2 + 1];
                } else {
                    tree[index] = tree[index * 2];
                    countTree[index] = countTree[index * 2] + countTree[index * 2 + 1];
                }
            }
            
            /*for (auto &x : tree)  
                cout << x << " ";
            cout << endl;
            for (auto &x : countTree)
                cout << x << " ";
            cout << endl;*/
        }
    }
    cout << endl;
    return 0;
}