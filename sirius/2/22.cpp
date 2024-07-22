#include <iostream>
#include <vector>
#define ll long long
using namespace std;

pair<int, int> f(int a, int b) {
    int si2 = 1;
    int ti2 = 0;
    int si1 = 0;
    int ti1 = 1;
    while (b != 0) {
        int k = a / b;
        int si = si2 - si1 * k;
        int ti = ti2 - ti1 * k;
        // cout << si2 << " " << ti2 << " " << si1 << " " << ti1 << " " << si << " " << ti << endl;
        si2 = si1;
        ti2 = si1;
        si1 = si;
        ti1 = ti;

        int r = a % b;
        a = b;
        b = r;
    }
    // cout << si2 << " " << ti2 << " " << si1 << " " << ti1 << endl;
    return {si2, ti2};
}

int nod(int a, int b) {
    while (b != 0) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    int a, m;
    cin >> m >> a;
    // cout << nod(a, m) << endl;
    if (nod(a, m) != 1) {
        cout << -1 << endl;
    } else {
        cout << (f(a, m).first + m) % m << endl;
    }
    // cout << f(3, 7).first << " " << f(3, 7).second << endl;
    return 0;
}