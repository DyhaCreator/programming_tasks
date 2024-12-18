#include <iostream>
#define ll long long
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 1;
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}