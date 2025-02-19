#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a = "";
    int f = 0;
    while (getline(cin, a)) {
        int n = a.size();
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == '/' && a[i + 1] == '*') {
                f = 1;
            } else if (a[i] == '*' && a[i + 1] == '/' && f > 2) {
                f = 0;
            } else if (a[i] == '/' && a[i + 1] == '/' && f == 0) {
                for (int j = i + 2; j < n - 1; j++) {
                    if (a[j] == '*' && a[j + 1] == '/') {
                        a.insert(j + 1, " ");
                    }
                }
                a[i + 1] = '*';
                a.push_back('*');
                a.push_back('/');
                break;
            }
            if (f > 0) f++;
        }
        cout << a << endl;

    }
    return 0;
}