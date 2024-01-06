#include <iostream>
#define ll long long
using namespace std;

int f(int n) {
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        ans *= 2;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    if (n < 6) {
        cout << f(n) << endl;
    } else {
        cout << 31 << endl;
    }
    return 0;
}