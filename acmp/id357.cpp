#include <iostream>
#define ll long long
using namespace std;

int main() {
    string num;
    cin >> num;
    ll sum_a = 0;
    ll sum_b = 0;
    for (int i = 0; i < num.size(); i++) {
        if (i % 2 == 0) {
            sum_a += num[i] - '0';
        } else {
            sum_b += num[i] - '0';
        }
    }
    if (abs(sum_a - sum_b) % 11 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}