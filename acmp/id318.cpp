#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 0;
    while ((n & (1 << i)) == 0 || (n & (1 << (i + 1))) != 0) {
        i++;
    }
    n = (n | (1 << (i + 1)));
    n = (n ^ (1 << i));
    cout << n << endl;
    return 0;
}