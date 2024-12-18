#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    for (int i = 3; i < n; i++) {
        a[i] = a[i - 1] + a[i - 2] - 2 * a[i - 3];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}