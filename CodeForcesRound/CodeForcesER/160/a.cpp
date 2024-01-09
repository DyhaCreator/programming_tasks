#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string ab;
        cin >> ab;
        bool ans = false;
        for (int j = 1; j < ab.size(); j++) {
            string sa = ab.substr(0, j);
            string sb = ab.substr(j);
            if (sa[0] != '0' && sb[0] != '0') {
                int a = stoi(sa);
                int b = stoi(sb);
                if (b > a) {
                    cout << a << " " << b << endl;
                    ans = true;
                    break;
                }
            }
        }
        if (!ans) {
            cout << -1 << endl;
        }
    }
    return 0;
}