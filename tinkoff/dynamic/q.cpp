#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> k >> n;
    vector<ll>a = vector<ll>(k, 0);
    vector<ll>b = vector<ll>(k + 1, 0);
    a[k - 1] = 1;
    b[k] = 1;
    for (int i = k; i < n + k; i++) {
        ll s = b[i] - b[i - k];
        s = s % 1000000007;
        a.push_back(s);
        b.push_back(b.back() + s);
    }
    cout << a[a.size() - 1] << endl;
    return 0;
}