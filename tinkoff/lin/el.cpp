#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll>a = vector<ll>(n);
    for (auto &x : a)
        cin >> x;
    vector<ll>sum = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i - 1];
    vector<ll>pref = vector<ll>(n - k + 1);
    for (int i = 0; i + k <= n; i++) {
        pref[i] = sum[i + k] - sum[i];
    }
    for (auto x : pref)
        cout << x << " ";
    cout << endl;
    int i = 2;
    cout << sum[i] - sum[i - k] << endl;
    
    return 0;
}
/*

6 2
4 2 2 3 1 3

*/