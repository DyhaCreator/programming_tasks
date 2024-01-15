#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string s, f;
        cin >> s >> f;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            //cout << s[j] << " " << f[j] << endl;
            if (s[j] == '0' && f[j] == '1') {
                if (j > 0 && s[j - 1] == '1' && f[j - 1] == '0') {
                    s[j] = 0;
                    f[j] = 0;
                } else {
                    ans++;
                }
            } else if (s[j] == '1' && f[j] == '0') {
                if (j > 0 && s[j - 1] == '0' && f[j - 1] == '1') {
                    s[j] = 0;
                    f[j] = 0;
                } else {
                    ans++;
                }
                //cout << "alf" << endl;
            }
            //cout << ans;
        }
        cout << ans << endl;
    }
    return 0;
}