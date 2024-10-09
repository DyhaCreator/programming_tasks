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
                double t = a - x[i];
                double a1 = b * b + 1;
                double b1 = 2 * t * b - 2 * y[i];
                double c1 = t * t + y[i] * y[i] - r[i] * r[i];
                double D = b1 * b1 - 4 * a1 * c1;
                /*cout << a << " " << b << endl;
                cout << a1 << " " << b1 << " " << c1 << endl;
                cout << D << endl;*/
                if (D >= 0) found = 1;
            }
        }
        if (found == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}