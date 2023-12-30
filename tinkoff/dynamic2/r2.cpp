#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, a1, k, b, m;
    cin >> n >> a1 >> k >> b >> m;
    vector<int>a = vector<int>(n);
    a[0] = a1;
    for (int i = 1; i < n; i++) {
        a[i] = (k * a[i - 1] + b) % m;
        //cout << a[i] << " ";
    }
    //cout << endl;
    vector<int>dp = vector<int>(n + 1, m + 1);
    dp[0] = -(m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (dp[j - 1] < a[i] && dp[j] > a[i]) {
                dp[j] = a[i];
            }
        }
    }
    /*for (auto x : dp) 
        cout << x << " ";
    cout << endl;*/
    int i = 1;
    while (dp[i] != m + 1) {
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}