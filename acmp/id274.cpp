#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool f(int a, int b) {
    vector<int> mp1(10);
    vector<int> mp2(10);
    while (a > 0) {
        mp1[a % 10]++;
        a /= 10;
    }
    while (b > 0) {
        mp2[b % 10]++;
        b /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if ((!mp1[i] && mp2[i]) || (mp1[i] && !mp2[i])) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        if (f(a, b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}