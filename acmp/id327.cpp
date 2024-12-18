#include <iostream>
#define ll long long
using namespace std;

int f(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        if (f((num + 1) % 1000) == f((num + 1) / 1000) || 
            f((num - 1) % 1000) == f((num - 1) / 1000)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}