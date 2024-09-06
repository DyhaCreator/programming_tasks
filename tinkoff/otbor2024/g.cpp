#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> g(2 * n, -1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1] = b - 1;
        g[b - 1] = a - 1;
    }
    int start = -1;
    ll plus = -1;
    for (int i = 0; i < 2 * n; i++) {
        if (i - g[i] == 1) {
            start = max(g[i], i);
            // plus = i + g[i];
            break;
        }
    }
    if (start == -1) {
        cout << "Yes" << endl;
        return 0;
    }
    int end = start - 1;
    vector<int> g2(2 * n, -1);
    for (int i = start; i < start + 2 * n; i++) {
        int index = i % (2 * n);
        g2[index] = end;
        end--;
        if (end < 0) end = 2 * n - 1;
    }
    if (g == g2) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}