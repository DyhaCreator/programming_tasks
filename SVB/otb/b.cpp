#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int l, k, u;
    cin >> l >> k >> u;
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    int p;
    cin >> p;
    vector<int> b(p);
    for (auto &x : b)
        cin >> x;
    int pos = 0;
    int index_a = 0;
    int start_b = 0;
    while (pos < l) {
        while (start_b < p && b[start_b] < pos) start_b++;
        int index = start_b;
        while (index < p && b[index] < a[index_a].F) index++;
        int col = index - start_b;
        if (a[index_a].F - pos <= k) {
            a[index_a].S -= u / (1 << col);
        }
        if (a[index_a].S <= 0) index_a++;
        else if (pos >= a[index_a].F) break;
        pos++;
    }
    cout << pos << endl;
    return 0;
}