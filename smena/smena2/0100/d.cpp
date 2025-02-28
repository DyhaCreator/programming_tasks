#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int nod(int a, int b) {
    while (b > 0) {
        a %= b;
        int buff = a;
        a = b;
        b = buff;
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int last = -1;
    int cnt = 1;
    int sec = 0;
    vector<int> ans = {};
    while (cnt != 0 || sec < 3) {
        cnt = 0;
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != -1) index++;
            if (a[i] != -1 && last != -1 && nod(last, a[i]) == 1) {
                a[i] = -1;
                last = -1;
                cnt++;
                ans.push_back(i);
                index--;
            } else if (a[i] != -1) {
                last = a[i];
            }
        }
        if (cnt == 0) sec++;
        /*for (auto &x : a)
            cout << x << " ";
        cout << endl;*/
    }
    cout << ans.size() << " ";
    for (auto &x : ans)
        cout << x + 1 << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}