#include <iostream>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = INF, b = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i * 5 + j * 3 == n && a + b > i + j) {
                a = i;
                b = j;
            }
        }
    }
    cout << a << " " << b << endl;
    return 0;
}