#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    ll a = 0, b = 1;
    while (n + 2 > 0) {
        a += b;
        b = a - b;
        a = a % 1000000007;
        b = b % 1000000007;
        n--;
    }
    cout << a << endl;
}