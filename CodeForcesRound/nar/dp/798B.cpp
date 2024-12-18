#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    int ansmin = INF;
    for (int j = 0; j < n; j++) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i != j) {
                string s = a[i];
                int count = 0;
                while (s != a[j]) {
                    char ch = s[0];
                    for (int i = 0; i < s.size() - 1; i++)
                        s[i] = s[i + 1];
                    s[s.size() - 1] = ch;
                    count++;
                    if (count > a[0].size() + 1) break;
                }
                if (count > a[0].size()) {
                    cout << -1 << endl;
                    return 0;
                }
                // cout << count << endl;
                ans += count;
            }
        }
        ansmin = min(ans, ansmin);
    }
    cout << ansmin << endl;
    return 0;
}