#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gsd (ll a, ll b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return max(a, b);
}

int main() {
    ll n;
    vector<ll> 
}