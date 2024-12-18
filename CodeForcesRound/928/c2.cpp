#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int f(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    vector<int> ans(200000 + 1);
    ans[0] = 0;
    for (int i = 1; i < ans.size(); i++) {
        ans[i] = ans[i - 1] + f(i);
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}