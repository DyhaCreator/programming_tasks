#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int f(string str, int l, int r) {
    int ans = 0;
    for (int i = 0; i < r / 2; i++) {
        //if (str[l + i] != str[l + r - i - 1]) {
            ans++;
        //}
    }

    return ans;
}
//?????????????????
int main() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        for (int j = 1; j <= str.size() - i; j++) {
            //string str2 = str.substr(i, j);
            //cout << str.substr(i, j) << " " << f(str, i, j) << " " << i << " " << j << endl;
            //if (f(str, i, j) <= k) {
                //cout << str.substr(i, j) << endl;
            int g = 0;
            for (int k = 0; k < str.size(); k++) {
                if (k % 2 == 0) {
                    g++;
                }
            }
            ans += g;
            //}
        }
    }
    cout << ans << endl;
    return 0;
}