#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll min(ll a, ll b) {
    if (a < b) {
        return a;
    }
    return b;
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
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = i; j < n; j++) {
            cout << min(a[j - 1], a[j]) << " ";
            sum += min(a[j - 1], a[j]);
        }
        cout << sum << endl;
    }
    return 0;
}