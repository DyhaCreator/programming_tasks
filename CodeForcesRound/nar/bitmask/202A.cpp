#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string ans = "ZZZZZZZZZZZZ";
    for (int i = 0; i < (1 << n); i++) {
        // cout << i << endl;
        string a = "";
        int save = i;
        int j = 0;
        while (save > 0) {
            if (save % 2 == 1) a.push_back(s[j]);
            save /= 2;
            j++;
        }
        // cout << a << endl;
        int found = 0;
        for (int j = 0; j < a.size() / 2; j++) {
            if (a[j] != a[a.size() - j - 1]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            ans = max(ans, a);
        }
    }
    cout << ans << endl;
    return 0;
}