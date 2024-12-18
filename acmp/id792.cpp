#include <iostream>
#define ll long long
using namespace std;

int f(int n, int p) {
    int ans = 0;
    while (n > 0) {
        ans += n % p;
        n /= p;
    }
    return ans;
}

int main() {
    int n1, p1;
    int n2, p2;
    cin >> n1 >> p1 >> n2 >> p2;
    if (f(n1, p1) == f(n2, p2)) {
        cout << f(n1, p1) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}