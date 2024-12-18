#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
    string let;
    getline(cin, let);
    int n;
    cin >> n;
    string sss;
    getline(cin, sss);
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        // cout << str << endl;
        bool find = 0;
        for (auto &x : str) {
            for (auto &y : let) {
                // cout << x << " " << y << " " << char(y + 32) << endl;
                if (x == y || x == y + 32) {
                    find = 1;
                    break;
                }
            }
            if (find) {
                cout << "no" << endl;
                break;
            }
        }
        if (!find) {
            cout << "yes" << endl;
        }
    }
    return 0;
}