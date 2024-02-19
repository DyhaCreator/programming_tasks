#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        int a = 0, b = 0;

        for (auto &x : str) {
            if (x == 'A') a++;
            if (x == 'B') b++;
        }
        if (a > b) {
            cout << 'A' << endl;
        } else {
            cout << 'B' << endl;
        }
    }
    return 0;
}