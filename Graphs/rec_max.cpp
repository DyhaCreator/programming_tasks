#include <iostream>
#define ll long long
using namespace std;

void rec(int n) {
    cout << n << endl;
    rec(n + 1);
}

int main() {
    rec(0);
    return 0;
}

// maximum is ~261700