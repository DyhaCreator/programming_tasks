#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool f(int n) {
    vector<int> mp(10, 0);
    while (n > 0) {
        mp[n % 10] = 1;
        n /= 10;
    }
    int count = 0;
    for (auto &x : mp)
        count += x;
    return count <= 2;
}

int main() {
    int n;
    cin >> n;
    int ansL = 0;
    int ansR = 0;
    while (!f(n - ansL)) {
        ansL++;
    }
    while (!f(n + ansR)) {
        ansR++;
    }
    if (ansL <= ansR) {
        cout << n - ansL << endl;
    } else {
        cout << n + ansR << endl;
    }
    return 0;
}