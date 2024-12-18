#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int sum(ll a) {
    ll sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

bool comp(pair<ll, int> a, pair<ll, int> b) {
    if (sum(a.first) == sum(b.first)) {
        return a.second < b.second;
    }
    return sum(a.first) > sum(b.first);
}

int main() {
    int n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end(), comp);
    for (auto &[x, i] : a)
        cout << x << " ";
    cout << endl;
    return 0;
}