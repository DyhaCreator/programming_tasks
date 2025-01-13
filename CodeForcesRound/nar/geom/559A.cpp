#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    vector<int> a(6);
    for (auto &x : a)
        cin >> x;
    cout << (a[0] + a[5]) * (a[1] + a[2]) * 2 - a[5] * a[5] - a[2] * a[2] << endl;
    return 0;
}