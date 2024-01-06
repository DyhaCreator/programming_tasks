#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int sum = 0;
        for (auto x : s) {
            if (x == '+') {
                sum++;
            } else {
                sum--;
            }
        }
        cout << abs(sum) << endl;
    }
    return 0;
}