#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int min(vector<int>a, int l, int r) {
    int min = 1e9 + 10;
    for (int i = l; i <= r; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    ll maxS = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ll s = min(a, i, j) * (j - i + 1);
            if (s > maxS) {
                maxS = s;
            }
        }
    }
    cout << maxS << endl;
    return 0;
}