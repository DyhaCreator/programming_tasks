#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> prime = {};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> pr(5000001, 0);
    for (int i = 2; i < pr.size(); i++) {
        if (pr[i] == 0) {
            for (int j = 2; i * j < pr.size(); j++) {
                pr[i * j] = 1;
            }
            prime.push_back(i);
        }
    }
    vector<int> cnt(pr.size());
    for (int i = 2; i < cnt.size(); i++) {
        int n = i;
        for (auto &x : prime) {
            while (n % x == 0) {
                cnt[i]++;
                n /= x;
            }
            if (pr[n] == 0) {
                break;
            }
        }
        if (n != 1) cnt[i]++;
    }
    vector<int> pref(cnt.size() + 1);
    for (int i = 0; i < cnt.size(); i++)
        pref[i + 1] = pref[i] + cnt[i];
    
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << pref[a + 1] - pref[b + 1] << endl;
    }
    return 0;
}