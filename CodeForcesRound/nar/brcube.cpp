#include <iostream>
#define ll long long
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (max(a, b) == 6) {
        cout << "1/6" << endl;
    } else if (max(a, b) == 5) {
        cout << "1/3" << endl;
    } else if (max(a, b) == 4) {
        cout << "1/2" << endl;
    } else if (max(a, b) == 3) {
        cout << "2/3" << endl;
    } else if (max(a, b) == 2) {
        cout << "5/6" << endl;
    } else if (max(a, b) == 1) {
        cout << "1/1" << endl;
    }
    return 0;
}