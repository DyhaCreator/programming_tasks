#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> pr(512);

bool comp(int a, int b) {
    return pr[a] < pr[b];
}


int main() {
    for (int i = 1; i < 512; i++) {
        int a = i;
        while (a != 2) {
            if (a % 2 == 0) {
                a /= 2;
            } else {
                a = a * 3 + 1;
            }
            pr[i]++;
        }
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end(), comp);
    int f = 0;
    int ans = pr[a[0]];
    for (int i = 1; i < n; i++) {
        if ((pr[a[i]] - pr[a[i - 1]]) % 3 == 0) {
            ans = max(ans, pr[a[i]]);
        } else {
            f = 1;
        }
    }
    if (f == 0) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}