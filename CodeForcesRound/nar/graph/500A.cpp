#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int index = 0;
    while (index + 1 < t)
        index += a[index];
    if (index + 1 == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}