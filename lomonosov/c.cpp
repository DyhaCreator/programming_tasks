#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        vector<char>ans = vector<char>();
        int x;
        cin >> x;
        if ((x < 0 && a > 0) || (x > 0 && a < 0) || a == 0) {
            cout << 0 << endl;
            break;
        }
        while (x != 0) {
            while (x % b == 0) {
                x /= b;
                ans.push_back('B');
            }
            x -= a;
            ans.push_back('A');
        }
        reverse(ans.begin(), ans.end());
        for (auto x : ans)
            cout << x << endl;
    }
    return 0;
}