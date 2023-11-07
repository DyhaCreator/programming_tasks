#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll>a = vector<ll>();
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    vector<ll>sum = vector<ll>(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    ll max = 0;
    for (int i = 0; i + k <= n; i++) {
        if (sum[i + k] - sum[i] > sum[max + k] - sum[max]) {
            max = i;
        }
    }
    //cout << max << endl;
    a.erase(a.begin() + max, a.begin() + max + k);
    /*for (auto x : a)
        cout << x << " ";
    cout << endl;*/
    sum = vector<ll>(n - k + 1, 0);
    for (int i = 1; i < sum.size(); i++) {
        sum[i] = sum[i - 1] + a[i - 1];
        //cout << sum[i] << " ";
    }
    //cout << endl;
    max = 0;
    for (int i = 0; i + k < sum.size(); i++) {
        if (sum[i + k] - sum[i] > sum[max + k] - sum[max]) {
            max = i;
        }
    }
    cout << sum[max + k] - sum[max] << endl;
    return 0;
}
/*

10 2
1 2 4 5 2 4 2 2 1 6

*/