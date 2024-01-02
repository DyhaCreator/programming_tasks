#include <iostream>
using namespace std;

int f(int n) {
    int ans1 = n % 10 + (n / 10 % 10);
    int ans2 = (n / 10 % 10) + (n / 100);
    if (ans1 > ans2) {
        return stoi(to_string(ans1) + to_string(ans2));
    } else {
        return stoi(to_string(ans2) + to_string(ans1));
    }
}

int main() {
    cout << f(179) << endl;
    int i = 100;
    while (f(i) != 126) {
        i++;
    }
    cout << i << " " << f(i) << endl;
    return 0;
}