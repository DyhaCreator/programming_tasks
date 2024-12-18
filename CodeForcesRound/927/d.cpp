#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n;

bool f(string &a, string &b, char k) {
    if (b[1] != k && a[1] != k && b[1] != a[1]) return false;
    if (a[1] != k && b[1] != k) {
        return a[0] < b[0];
    } else if (a[1] != k && b[1] == k) {
        return true;
    } else if (a[1] == k && b[1] != k) {
        return false;
    } else {
        return a[0] < b[0];
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << i << " ";
        cin >> n;
        char k;
        cin >> k;
        vector<string> cards(n * 2);
        for (auto &x : cards)
            cin >> x;
        bool b = false;
        for (int y = 0; y < n - 1; y++) {
            for (int x = y + 1; x < n; x++) {
                if (f(cards[y], cards[x], k)) {
                    cout << cards[y] << " " << cards[x] << endl;
                    b = true;
                } else if (f(cards[x], cards[y], k)) {
                    cout << cards[x] << " " << cards[y] << endl;
                    b = true;
                }
                if (b == true) break;
            }
            if (b == true) break;
        }
        if (b == false) {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}