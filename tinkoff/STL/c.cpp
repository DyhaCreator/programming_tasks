#include <iostream>
#include <sstream>
#include <string>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while (getline(cin, str)) {
        stringstream ss(str);
        int n, sum = 0;
        while (ss >> n) {
            sum += n;
        }
        cout << sum << endl;
    }
    return 0;
}