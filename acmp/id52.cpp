#include <iostream>
#define ll long long
using namespace std;

int main() {
    string num;
    cin >> num;
    int a = 0;
    int b = 0;
    for (int i = 0; i < 3; i++) a += num[i];
    for (int i = 3; i < 6; i++) b += num[i];
    if (a == b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}