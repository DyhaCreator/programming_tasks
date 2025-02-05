#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> l = {};
    vector<int> c = {};
    vector<int> r = {};
    for (auto &x : a) {
        if (x > 0) l.push_back(x);
        else if (x < 0) r.push_back(x);
        else c.push_back(x);
    }
    for (auto &x : l) cout << x << " ";
    for (auto &x : c) cout << x << " ";
    for (auto &x : r) cout << x << " ";
    cout << endl;
    return 0;
}