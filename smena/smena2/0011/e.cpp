#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string st = s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            while (s[i] == s[i - 1] || (i < n - 1 && s[i] == s[i + 1])) {
                int r = rand() % 3;
                if (r == 0) s[i] = 'R';
                else if (r == 1) s[i] = 'G';
                else if (r == 2) s[i] = 'B';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != st[i]) ans++;
    }
    cout << ans << endl;
    cout << s << endl;
    return 0;
}