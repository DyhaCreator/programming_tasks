#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int k, n;
    cin >> k >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    k--;
    cout << a[k % n] << endl;
    return 0;
}