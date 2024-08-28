#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int maxj = 0;
    int ans1 = 0, ans2 = 0;
    int max_ans = -1;
    for (int i = k + 1; i < n; i++) {
        if (max_ans == -1 || a[i] + a[maxj] > max_ans) {
            ans1 = maxj;
            ans2 = i;
            max_ans = a[i] + a[maxj];
        }
        if (maxj == -1 || a[i - k] > a[maxj])
            maxj = i - k;
    }
    cout << ans1 + 1 << " " << ans2 + 1 << endl;
    return 0;
}