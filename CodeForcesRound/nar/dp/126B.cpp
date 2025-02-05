#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    int n = a.size();
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 1; i < n; i++) {
        int cur = l[i - 1];
        while (a[i] != a[cur] && cur > 0)
            cur = l[cur - 1];
        if (a[i] == a[cur])
            l[i] = cur + 1;
    }
    reverse(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        int cur = r[i - 1];
        while (a[i] != a[cur] && cur > 0)
            cur = r[cur - 1];
        if (a[i] == a[cur])
            r[i] = cur + 1;
    }
    reverse(r.begin(), r.end());
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] == r[i - l[i] + 1]) {
            mx = max(min(l[i], r[i - l[i] + 1]), mx);
        }
    }
    if (mx == 0) {
        cout << "Just a legend" << endl;
        return 0;
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < mx; i++)
        cout << a[i];
    cout << endl;
    return 0;
}