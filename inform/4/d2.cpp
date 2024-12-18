#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

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
            if (i != j) {
                if (x[i] == x[j] && x[i] == x[j] && r[i] == r[j]) found = 1;
                double a = (double)(x[j] * x[j] - x[i] * x[i] - y[i] * y[i] + y[j] * y[j] + r[i] * r[i] - r[j] * r[j]) / (2 * x[j] - 2 * x[i]);
                double b = (double)(2 * y[i] - 2 * y[j]) / (2 * x[j] - 2 * x[i]);
                double c = b * b + 1;
                double d = 2 * (a - x[i]) * b - 2 * y[i];
                double e = (a - x[i]) * (a - x[i]) + y[i] * y[i] - r[i] * r[i];
                double D = d * d - 4 * c * e;
                if (D >= 0) found = 1;
            }
        }
        if (found == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}