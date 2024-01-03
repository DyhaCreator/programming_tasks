#include <iostream>
#define ll long long
using namespace std;

int nod(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << " " << n / 2 << endl;
        return 0;
    }
    int maxn = 1;
    int maxNod = 1;
    for (int i = 3; i < n / 2; i += 2) {
        int nodI = nod(i, n - i);
        if (nodI > maxNod) {
            maxNod = nodI;
            maxn = i;
        }
    }
    cout << maxn << " " << n - maxn << endl;
    return 0;
}