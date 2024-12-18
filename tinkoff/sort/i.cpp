#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int>a = vector<int>(26, 0);
    int asize = 25;
    for (int i = 0; i < str.size(); i++) {
        a[str[i] - 65]++;
    }
    string ans = "";
    for (int i = 0; i <= asize; i++) {
        for (int j = 0; j < a[i] / 2; j++) {
            ans += char(i + 65);
        }
    }
    reverse(ans.begin(), ans.end());
    string ans2 = ans;
    reverse(ans.begin(), ans.end());
    for (int i = 0; i <= asize; i++) {
        if (a[i] % 2 == 1) {
            ans += char(i + 65);
            break;
        }
    }
    cout << ans + ans2 << endl;
    return 0;
}