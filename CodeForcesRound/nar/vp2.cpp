#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll f(int n) {
    return (1 << n) - 1;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        vector<ll>a = {};
        int min = 100;
        x--;
        while (x > 0) {
            ll n = 1;
            while (f(n) <= x) {
                n++;
            }
            n--;
            cout << n << endl;
            if (x >= (f(n) * 2) - 1) {
                a.push_back(min - n);
                x -= f(n);
                cout << "Y" << endl;
            }
            // vector<int>b = {};
            for (int j = 0; j < n; j++) {
                a.push_back(min + j - n);
            }
            min = min - n;
            x -= f(n);
        }
        cout << a.size() << endl;
        for (auto &x : a)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}