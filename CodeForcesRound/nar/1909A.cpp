#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2{
    int x, y;
    int2() {}
    int2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int2>a1(n);
        int a = 0, b = 0, c = 0, d = 0;
        for (auto &x : a1) {
            cin >> x.x >> x.y;
            if (x.x > 0 && x.y > 0) {
                a++;
            } else if (x.x > 0 && x.y < 0) {
                b++;
            } else if (x.x < 0 && x.y > 0) {
                c++;
            } else if (x.x < 0 && x.y < 0) {
                d++;
            }
        }
        if ((a > 0 && d > 0) || (c > 0 && b > 0) || 
            (a > 0 && b > 0) || (a > 0 && c > 0) || (c > 0 && d > 0) || (d > 0 && b > 0)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}