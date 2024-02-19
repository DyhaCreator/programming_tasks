#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

char k;

bool f(string &a, string &b) {
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
        int n;
        cin >> n;
        cin >> k;
        vector<string> cards(n * 2);
        for (auto &x : cards)
            cin >> x;
        sort(cards.begin(), cards.end(), f);
        for (int j = 0; j < 2*n - 1; j+=2) {
            cout << cards[j] << " " << cards[j + 1] << endl;
        }
    }
    return 0;
}