#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        string a, b, c;
        cin >> n;
        cin >> a >> b >> c;
        string str;
        for (int j = 0; j < n; j++) {
            if (a[j] == b[j]) {
                str += a[j];
            } else {
                if (a[j] != c[j] && b[j] != c[j]) {
                    str += c[j] - 32;
                } else {
                    str += '.';
                }
            }
        }
        //cout << str << endl;
        int j = 0;
        while (j < n && (str[j] == c[j] || str[j] == '.')) {
            j++;
        }
        if (j == n) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}