#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int n;

void turn(vector<string> &a) {
    vector<string> b = a;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            b[y][x] = a[x][n - y - 1];
        }
    }
    a = b;
}

int main() {
    cin >> n;
    vector<string> a(n);
    vector<string> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    int found = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (a[y][x] == b[y][x]) found = 1;
        }
    }
    if (found == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    turn(b);
    found = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (a[y][x] == b[y][x]) found = 1;
        }
    }
    if (found == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    turn(b);

    found = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (a[y][x] == b[y][x]) found = 1;
        }
    }
    if (found == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    turn(b);

    found = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (a[y][x] == b[y][x]) found = 1;
        }
    }
    if (found == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}