#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (auto &x : v) {
            cin >> x;
        }
        bool find = false;
        for (int y = 0; y < n - 1; y++) {
            for (int x = 0; x < n - 1; x++) {
                if (v[y][x] == '1' && v[y + 1][x] == '1' && v[y][x + 1] == '1') {
                    cout << "SQUARE" << endl;
                    find = true;
                } else if (v[y][x] == '1') {
                    // cout << v[y][x] << " " << v[y + 1][x] << " " << v[y][x + 1] << endl;
                    cout << "TRIANGLE" << endl;
                    find = true;
                }
                if (find) break;
            }
            if (find) break;
        }
    }
    return 0;
}