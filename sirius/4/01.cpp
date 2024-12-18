#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll cnt = 0, y = 1;
    while (y < n) {
        y = y << 1;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}