#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];
    int ib = 0;
    int jb = 1;
    int imin = 0;
    for (int j = 1; j <= n; j++) {
        if (p[jb] - p[ib - 1] < p[j] - p[imin - 1]) {
            jb = j;
            ib = imin;
        }
        if (p[imin] >= p[j])
            imin = j;
    }
    cout << ib + 1 << " " << jb << endl;
    return 0;
}