#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    double sum = 0;
    int first;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) first = x;
        if (i > 0 && abs(x - first) > 180) {
            if (x >= first) {
                x = x - 360;
            } else {
                x = 360 + x;
            }
        }
        sum += x;
    }
    int s = sum / n + 360;
    int l = 0, r = 60;
    while (l < r) {
        int m = (l + r) / 2;
        if (s + ((double)m / 60.0) < sum / n + 360) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (r == 60) {
        r = 0;
        s++;
    }
    cout << (s + 360) % 360 << " ";
    cout << r << endl;
    return 0;
}