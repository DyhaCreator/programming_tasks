#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int found = 0;
    for (int x = 0; x <= (n - x) / (x + 1); x++) {
        if ((n - x) % (x + 1) == 0) {
            if (x == (n - x) / (x + 1)) found = 1;
            // cout << x << " " << (n - x) / (x + 1) << endl;
            ans++;
        }
    }
    if (found) ans--;
    cout << ans * 2 + found << endl;
    return 0;
}