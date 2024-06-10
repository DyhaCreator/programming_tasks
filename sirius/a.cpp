#include <iostream>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    ll ans = ((n + 1) * n) / 2 * n;
    cout << ans << endl;
    return 0;
}