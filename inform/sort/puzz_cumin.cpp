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
    for (auto &x : a) x = rand() % 10;
    for (auto &x : a) cout << x << " ";
    cout << endl;
    for (auto &x : a)
        for (int i = 1; i < n; i++)
            if (a[i - 1] > a[i]) swap(a[i - 1], a[i]);
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}