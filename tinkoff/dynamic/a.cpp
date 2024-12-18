#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int>a;

int f(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return f(n - 1) + f(n - 2);
}

int main() {
    int n;
    cin >> n;
    a = vector<int>(n);
    cout << f(n) << endl;
    return 0;
}