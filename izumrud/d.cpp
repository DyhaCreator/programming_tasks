#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string f2(int n) {
    string ans = "";
    while (n > 0) {
        ans += to_string(n % 8);
        n /= 8;
    }
    reverse(ans.begin(), ans.end());
    string a = "";
    a += ans[0];
    a += ans[1];
    return a;
}

int f(int n) {
    return (n % 16);
}

int main() {
    int n = 0;
    while (f(n) != 0x7 || f2(n) != "26") {
        n++;
    }
    cout << n << endl;
}