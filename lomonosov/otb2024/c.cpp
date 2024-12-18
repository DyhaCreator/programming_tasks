#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f(string s) {
    int num = 0;
    stringstream in(s);
    char a, b;
    in >> a >> num >> b;
    if (a == 'N') {
        if (b == 'W') {
            num = -num;
        }
    } else if (a == 'S') {
        if (b == 'E') {
            num = 180 - num;
        } else if (b == 'W') {
            num = - (180 - num);
        }
    } else if (a == 'E') {
        if (b == 'N') {
            if (num <= 90) {
                num = 90 - num;
            } else {
                num -= 90;
                num = -num;
            }
        } else if (b == 'S') {
            if (num <= 90) {
                num += 90;
            } else {
                num = 180 - (num - 90);
                num = -num;
            }
        }
    } else if (a == 'W') {
        if (b == 'N') {
            if (num <= 90) {
                num = 90 - num;
            } else {
                num -= 90;
                num = -num;
            }
        } else if (b == 'S') {
            if (num <= 90) {
                num += 90;
            } else {
                num = 180 - (num - 90);
                num = -num;
            }
        }
        num = -num;
    }
    // cout << num << endl;
    if (num < 0) {
        num = 360 + num;
    }
    return num % 360;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        string s;
        cin >> s;
        x = f(s);
    }
    vector<int> count(360);
    vector<int> last(360);
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
        last[a[i]] = i + 1;
    }
    int mx = 0;
    int l = 0;
    for (int i = 0; i < 360; i++) {
        if (count[i] >= mx) {
            mx = count[i];
            l = last[i];
        }
    }
    cout << l << endl;
    return 0;
}