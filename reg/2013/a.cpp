#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int t;
    int n, a, b, c;
    cin >> t;
    cin >> n >> a >> b >> c;
    if (t == 1) {
        vector<int> d = {a, b, c};
        sort(d.begin(), d.end());
        cout << max(0, d[0] + d[1] - n - (n - d[2])) << endl;
    } else {
        cout << min(a, min(b, c)) << endl;
    }
    return 0;
}