#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    unsigned int start_time =  clock();
    vector<int> g(2 * n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1] = b - 1;
        g[b - 1] = a - 1;
    }
    vector<int> used(2 * n, 0);
    for (int i = 0; i < 2 * n; i++) {
        if (abs(i - g[i]) == 1) {
            used[i] = 1;
            used[g[i]] = 1;
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        if (used[i] == 0) {
            if (g[i] - i < 2 * n - g[i] + i) {
                for (int j = i; j < g[i]; j++) {
                    if (g[j] > g[i]) {
                        // cout << i << " " << g[i] << " " << j << " " << g[j] << endl;
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
            used[i] = 1;
            used[g[i]] = 1;
        }
    }
    cout << "NO" << endl;
    unsigned int end_time = clock();
    cout << (double)(end_time - start_time) / CLOCKS_PER_SEC * 10 << endl;
    return 0;
}