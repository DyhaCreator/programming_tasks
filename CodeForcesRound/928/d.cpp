#include <iostream>
#include <vector>
#include <map>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int a = 0;
    int mi = (1 << 31) - 1;
    // cout << ~a - mi << endl;
    a = ~a - mi - 1;
    /*while (a > 0) {
        cout << a % 2;
        a /= 2;
    }
    cout << endl;*/
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;
        map<int, int> mp;
        for (auto &x : nums)
            mp[x]++;
        int ans = 0;
        for (auto &x : nums) {
            // cout << (a ^ x) << endl;
            if (mp[a ^ x] > 0) {
                mp[x]--;
                mp[a ^ x]--;
            } else {
                ans++;
                mp[x]--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}