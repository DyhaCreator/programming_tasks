#include <iostream>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = n / 5;
    if (n % 5 == 1 || n % 5 == 2 || n % 5 == 3) {
        ans--;
    }
    return 0;
}