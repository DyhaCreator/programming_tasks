#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int imp(int a, int b) {
    if (a == 0 && b == 0) return 1;
    if (a == 0 && b == 1) return 1;
    if (a == 1 && b == 0) return 0;
    return 1;
}

bool f(int d, int n) {
    int a = (n & 0b100) >> 2;
    int b = (n & 0b010) >> 1;
    int c = n & 0b1;
    return imp(imp(imp(imp(d, (a & b & c)), (a & b | c)), (a | b & c)), (a | b | c));
}

int main() {
    vector<int> ans(8);
    for (int i = 0; i < 2; i++) {
        for (int n = 0; n < 8; n++) {
            if (f(i, n) == 1) {
                ans[n] ++;
            }
        }
    }
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}