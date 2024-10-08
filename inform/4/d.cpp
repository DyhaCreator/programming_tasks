#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            // cout << i << " " << j << " " << dist(x[i], y[i], x[j], y[j]) << " " << (r[i] + r[j]) << endl;
            if (i != j && dist(x[i], y[i], x[j], y[j]) < (r[i] + r[j])) {
                found = 1;
            }
        }
        if (found == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}