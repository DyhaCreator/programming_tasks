#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        string ans = "";
        for (int j = 0; j < n;) {
            if (j != 0) {
                ans += '.';
            }
            if (j + 3 < n) {
                if (str[j + 3] == 'a' || str[j + 3] == 'e') {
                    ans += str[j];
                    ans += str[j + 1];
                    j += 2;
                } else if (str[j + 3] == 'b' || str[j + 3] == 'c' || str[j + 3] == 'd') {
                    ans += str[j];
                    ans += str[j + 1];
                    ans += str[j + 2];
                    j += 3;
                }
            } else {
                if (n - j == 2) {
                    ans += str[j];
                    ans += str[j + 1];
                    j += 2;
                } else {
                    ans += str[j];
                    ans += str[j + 1];
                    ans += str[j + 2];
                    j += 3;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}