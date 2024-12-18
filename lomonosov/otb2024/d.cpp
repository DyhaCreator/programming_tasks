#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f(string a) {
    ll n = a.size();
    ll ans = 0;
    ll st = 1;
    vector<ll> nums = {};
    for (int i = 0; i < n; i++) {
        int f = 0;
        int num = a[i] - 'a';
        if (i + 1 < n) {
            if (a[i + 1] == '^') {
                num += 26;
                f = 1;
            } else if (a[i + 1] == '~') {
                num += 52;
                f = 1;
            } else if (a[i + 1] == '_') {
                num += 78;
                f = 1;
            }
        }
        nums.push_back(num);
        if (f) i++;
    }
    reverse(nums.begin(), nums.end());
    for (auto &x : nums) {
        ans += st * x;
        st *= 26;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    int ans = f(s);
    int index = 0;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (f(a) == ans && index == 0) {
            index = i + 1;
        }
    }
    cout << index << endl;
    return 0;
}