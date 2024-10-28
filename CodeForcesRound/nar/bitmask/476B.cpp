#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a, b;
    cin >> a >> b;
    int count = 0;
    for (auto &x : b)
        if (x == '?') count++;
    int ee = 0;
    for (auto &x : a) {
        if (x == '+') ee++;
        else ee--;
    }
    int cc = 0;
    for (int i = 0; i < (1 << count); i++) {
        int c = 0;
        int y = 0;
        for (auto &x : b) {
            if (x == '+') y++;
            else if (x == '-') y--;
            else {
                if ((i & (1 << c)) > 0) y++;
                else y--;
                c++;
            }
        }
        if (y == ee) cc++;
    }
    cout << fixed << setprecision(10) << (double)cc / (double)(1 << count) << endl;
    return 0;
}