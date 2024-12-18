#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int minj = 0;
    double maxR = -1;
    int ans1 = 0, ans2 = 1;
    for (int i = 1; i < n; i++) {
        if (maxR == -1 || (double)a[i] / (double)a[minj] > maxR) {
            ans1 = minj;
            ans2 = i;
            maxR = (double)a[i] / (double)a[minj];
            // cout << a[i] << " " << a[minj] << " " << (double)a[i] / (double)a[minj] << " " << maxR << endl;
        }
        if (a[i] < a[minj])
            minj = i;
    }
    if (maxR > 1.0) cout << ans1 + 1 << " " << ans2 + 1 << endl;
    else cout << "0 0" << endl;
    return 0;
}