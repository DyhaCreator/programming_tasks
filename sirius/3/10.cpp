#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int round2 = 1;

int nod(int a, int b) {
    if (a == 1 || b == 1) return 1;
    while (b > 0) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int nodInLine(int l, int r, vector<int> &tree) {
    l += round2;
    r += round2;
    int ans = 0;
    while (l <= r) {
        if (l % 2 != 0) {
            if (ans == 0) ans = tree[l];
            ans = nod(ans, tree[l]);
        }
        if (r % 2 == 0) {
            if (ans == 0) ans = tree[r];
            ans = nod(ans, tree[r]);
        }
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    
    while (round2 < n) {
        round2 *= 2;
    }
    vector<int> tree(round2 * 2, 1);
    for (int i = 0; i < n; i++) {
        tree[i + round2] = a[i];
    }

    for (int i = round2 - 1; i > 0; i--) {
        tree[i] = nod(tree[i * 2], tree[i * 2 + 1]);
    }

    /*for (auto &x : tree)
        cout << x << " ";
    cout << endl;*/
    
    // cout << nodInLine(1, 2, tree) << endl;

    int nodLine = a[0];
    int maxLen = 0;

    int j = 0;
    for (int i = 0; i < n; i++) {
        nodLine = nod(nodLine, a[i]);
        while (nodLine == 1 && j < i) {
            j++;
            nodLine = nodInLine(j, i, tree);
            // cout << j << " " << i << " " << nodLine << endl;
        }
        maxLen = max(maxLen, i - j + 1);
        // cout << j << " " << i << " " << nodLine << endl;
    }
    cout << maxLen << endl;
    return 0;
}