#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int>a = vector<ll>(n);
    for (auto &x : a)
        cin >> x;
    vector<ll>pref = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i - 1];
    
    return 0;
}