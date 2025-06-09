#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto &x : s) {
        if (x == 'R') {
            int sum = 0;
            for (auto &y : s) {
                if (y == 'S') {
                    sum++;
                } else if (y == 'P') {
                    sum--;
                }
            }
            cout << sum << " ";
        } else if (x == 'S') {
            int sum = 0;
            for (auto &y : s) {
                if (y == 'P') {
                    sum++;
                } else if (y == 'R') {
                    sum--;
                }
            }
            cout << sum << " ";
        } else if (x == 'P') {
            int sum = 0;
            for (auto &y : s) {
                if (y == 'R') {
                    sum++;
                } else if (y == 'S') {
                    sum--;
                }
            }
            cout << sum << " ";
        }
    }
    cout << endl;
    return 0;
}