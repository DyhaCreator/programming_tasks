#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    string b = "";
    for (auto &x : a) {
        if ((x >= '0' && x <= '9') || (x >= 'a' && x <= 'z')) {
            b.push_back(x);
        } else if (x >= 'A' && x <= 'Z') {
            b.push_back(x + 32);
        }
    }
    cout << b << endl;
    return 0;
}