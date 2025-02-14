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
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    for (int i = 1; i <= n; i++)
        cout << pref[i] << " ";
    cout << endl;
    return 0;
}