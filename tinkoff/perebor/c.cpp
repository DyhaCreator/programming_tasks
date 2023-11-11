#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, k;

ll sum(vector<int>a) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    return ans;
}

void rec(int n, vector<int>a) {
    if (n == 0) {
        if (sum(a) == k) {
            for (auto x : a)
                cout << x;
            cout << endl;
        }
        return;
    }
    a.push_back(0);
    rec(n - 1, a);
    a[a.size() - 1]++;
    rec(n - 1, a);
}

int main() {
    cin >> n >> k;
    rec(n, vector<int>());
    return 0;
}