#include <iostream>
#define ll long long
using namespace std;

int f(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    int k, m, n;
    cin >> k >> m >> n;
    cout << max(f(n * 2, k), 2) * m << endl;
    return 0;
}