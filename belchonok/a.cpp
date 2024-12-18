#include <iostream>
#define ll long long
using namespace std;

int f(int a) {
    int ans = 0;
    while (a > 0) {
        if (a % 10 == 6) {
            ans++;
        }
        a /= 10;
    }
    return ans;
}

int main() {
    int ans = 1;
    for (int i = 1; i < 100000000; i++) {
        if (f(i) <= 1) {
            ans++;
        }
        //cout << i << " " << f(i) << endl;
    }
    cout << ans << endl;
    return 0;
}