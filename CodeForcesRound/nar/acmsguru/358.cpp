#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    vector<int> a(3);
    vector<int> b(3);
    vector<int> c(3);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (auto &x : c)
        cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<int> d = {a[1], b[1], c[1]};
    sort(d.begin(), d.end());
    cout << d[1] << endl;
    return 0;
}