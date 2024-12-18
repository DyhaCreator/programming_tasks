#include <iostream>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 2;
    if (n % i == 1) {
        for (; i < n + 1; i += 2) {
            if (n % i == 0)
                break;
        }
    }
    cout << (i - 1) * (n / i) << " " << n / i << endl;
    return 0;
}