#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 7;

ull f(ull n) {
    return (n * n + 2 * n) * (n + 1) / 6 - n - 1;
}

int main() {
    ll n;
    cin >> n;
    ll l = 0;
    ll r = 1900000;
    /*for (int i = 2; i < 10; i++)
        cout << f(i) << " ";
    cout << endl;*/
    int i = 2;
    while (f(i) <= n) {
        i++;
    }
    i--;
    // cout << f(i) << " " << i - 1 << endl;
    cout << i - 1 << endl;
    return 0;
}