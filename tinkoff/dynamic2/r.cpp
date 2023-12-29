#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int a, k, b, m;
    cin >> a >> k >> b >> m;
    vector<int>a = vector<int>()
    a[0] = a1;
    for (int i = 1; i < n; i++) {
        a[i] = (k * a[i - 1] + b) % m;
    }
    return 0;
}