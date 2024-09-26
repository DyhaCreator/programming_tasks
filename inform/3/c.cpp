#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    double sum = 0;
    for (auto &x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        int x;
        x = a[i];
        if (i > 0) {
            if (abs(x - a[0]) > 40) {
                if (x > a[0]) {
                    x = x - 360;
                } else {
                    x = 360 + x;
                }
            }
        }
        a[i] = x;
        sum += x;
    }
    // cout << sum / n << endl;
    int s = sum / n;
    int ans = 0;
    // cout << sum / n << endl;
    for (int i = 1; i <= 60; i++) {
        if (abs(s + ((double)i / 60.0) - sum / n) <= abs(s + ((double)ans / 60.0) - sum / n)) ans = i;
    }
    /*cout << abs(s + ((double)ans / 60.0) - sum / n) << endl;
    cout << abs(s - sum / n) << endl;*/
    if (ans == 60) {
        s++;
        ans = 0;
    }
    if (s >= 360) cout << s - 360 << " ";
    else if (s < 0) cout << s + 360 << " ";
    else cout << s << " ";
    cout << ans << endl;
    return 0;
}