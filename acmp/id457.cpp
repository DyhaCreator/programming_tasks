#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int f(int n) {
    vector<int> num = {
        n % 10,
        n / 10 % 10,
        n / 100 % 10,
        n / 1000 % 10
    };
    sort(num.begin(), num.end());
    int num1 = num[0] + num[1] * 10 + num[2] * 100 + num[3] * 1000;
    reverse(num.begin(), num.end());
    int num2 = num[0] + num[1] * 10 + num[2] * 100 + num[3] * 1000;
    return num1 - num2;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (f(n) != n) {
        n = f(n);
        ans++;
    }
    cout << n << endl;
    cout << ans << endl;
    return 0;
}