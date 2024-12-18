#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int>prime = {};

bool isPrime(int i) {
    for (int a : prime)
        if (i % a == 0) return false;
    return true;
}

int main() {
    /*for (int i = 2; i < 10; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
            cout << i << " ";
        }
    }
    cout << endl;*/
    ll a, p;
    cin >> a >> p;
    int y = 0;
    while ((p * y + 1) % a != 0) {
        y++;
    }
    cout << (p * y + 1) / a << endl;
    /*for (int p : prime) {
        for (int a = 0; a < p; a++) {
            int y = 0;
            while ((p * y + 1) % a != 0) {
                y++;
            }
            int x = 1;
            while ((a * x - 1) % p != 0) {
                x++;
            }
            if ((p * y + 1) / a == x) {
                //cout << (p * y + 1) / a << endl;
                //cout << "s " << a << " " << p << " " << (p * y + 1) / a << endl;
            } else {
                cout << "b " << a << " " << p << " " << (p * y + 1) / a << " " << x << endl;
            }
        }
    }*/
    return 0;
}