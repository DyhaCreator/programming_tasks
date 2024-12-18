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
        vector<int> count(27);
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
        //cout << i << " ";
        if (ccc > count[k - 'A']) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        } else {
            //cout << endl;
        }
        vector<int> used(2 * n);
        for (int y = 0; y < 2 * n; y++) {
            if (used[y] == 0) {
                int minIndex = -1;
                for (int x = 0; x < 2 * n; x++) {
                    if (x != y && used[x] == 0) {
                        //cout << y << " " << x << endl;
                        if (f(cards[y], cards[x], k) && (minIndex == -1 || f(cards[x], cards[minIndex], k))) {
                            minIndex = x;
                        }
                    }
                }
                if (minIndex != -1) {
                    //cout << minIndex << endl;
                    cout << cards[y] << " " << cards[minIndex] << endl;
                    used[y] = 1;
                    used[minIndex] = 1;
                }
            }
        }
    }
    return 0;
}