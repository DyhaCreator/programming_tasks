#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;cin >> n;
    int ans = 0;
    while (cin >> n)
        if (n % 3 == 0 && n % 5 != 0) ans++;
    cout << ans << endl;
    return 0;
}