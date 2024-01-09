#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        vector<string>a = vector<string>(10);
        for (auto &x : a)
            cin >> x;
        int ans = 0;
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                if (a[y][x] == 'X') {
                    if (x == 0 || y == 0 || x == 9 || y == 9) {
                        ans += 1;
                    } else if (x == 1 || y == 1 || x == 8 || y == 8) {
                        ans += 2;
                    } else if (x == 2 || y == 2 || x == 7 || y == 7) {
                        ans += 3;
                    } else if (x == 3 || y == 3 || x == 6 || y == 6) {
                        ans += 4;
                    } else {
                        ans += 5;
                    }
                }
            } 
        }
        cout << ans << endl;
    }
    return 0;
}