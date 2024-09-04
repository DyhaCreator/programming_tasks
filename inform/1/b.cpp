#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    int m = n;
    int x = n;
    while (k > 0) {
        int r;
        cin >> r;
        if (m > r) {
            m = r;
        }
        x = r - (n - x);
        if (x < 0) {
            x = 0;
        }
        k--;
    }
    cout << x << " " << m << endl;
    return 0;
}