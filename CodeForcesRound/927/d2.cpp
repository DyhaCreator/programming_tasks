#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

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
        int n;
        cin >> n;
        char k;
        cin >> k;
        vector<string> cards(n * 2);
        for (auto &x : cards)
            cin >> x;
        vector<int> count(26);
        for (auto &x : cards) {
            count[x[1] - 'A']++;
        }
        /*for (auto &x : count)
            cout << x << " ";
        cout << endl;*/
        int ccc = 0;
        for (char i = 0; i < 26; i++) {
            if (count[i] % 2 == 1 && i + 'A' != k) {
                ccc++;
            }
        }
        cout << ccc << endl;
        if (ccc > count[k - 'A']) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        
    }
    return 0;
}