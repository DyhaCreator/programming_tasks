#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<int> dp(n);
    string r = "RGB";
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        if (a[i] == a[i - 1]) {
            dp[i]++;
            while (a[i] == a[i - 1] || (i < n - 1 && a[i] == a[i + 1]))
                a[i] = r[rand() % 3];
        }
    }
    cout << dp[n - 1] << endl;
    cout << a << endl;
    return 0;
}