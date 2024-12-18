#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        int x = 0;
        int ans = 0;
        while (x < n) {
            if (str[x] == 'B') {
                x += k;
                ans++;
            } else {
                x++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}