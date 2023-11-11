#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n;
vector<vector<int>>w;

ll min_sum = 1e18 + 10;

void rec(vector<int>l, int index, int cindex, ll sum) {
    if (index == cindex) {
        min_sum = min(sum, min_sum);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (l[i] == 0) {
            l[i] = 1;
            rec(l, i, cindex, sum + w[index][i]);
            l[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    w = vector<vector<int>>(n, vector<int>(n));
    for (auto &x : w)
        for (auto &y : x)
            cin >> y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                min_sum = 1e18 + 10;
                vector<int>a = vector<int>(n, 0);
                a[i] = 1;
                rec(a, i, j, 0);
                cout << min_sum << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}