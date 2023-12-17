#include <iostream>
#define ll long long
using namespace std;

int f(int num) {
    int ans = 0;
    while (num > 0) {
        if (num % 4 == 0) {
            ans++;
        }
        num /= 16;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ans += f(num);
    }
    cout << ans << endl;
    return 0;
}