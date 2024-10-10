#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int a;
    int ans = 0;
    while (cin >> a)
        ans += a;
    cout << ans << endl;
    return 0;
}