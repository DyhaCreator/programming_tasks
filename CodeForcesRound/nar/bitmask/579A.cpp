#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n > 0) {
        ans += n % 2;
        n /= 2;
    }
    cout << ans << endl;
    return 0;
}