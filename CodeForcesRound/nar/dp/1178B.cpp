#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    int n = a.size();
    vector<ll> count(n + 1);
    for (int i = 1; i < n; i++)
        count[i + 1] = count[i] + (a[i] == a[i - 1] && a[i] == 'v');
    ll ans = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 'o') ans += count[i] * (count[n] - count[i + 1]);
    cout << ans << endl;
    return 0;
}