#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

ll Psize = 16000000;

vector<ll> prime(Psize, 1);

int main() {
    int k;
    cin >> k;
    prime[0] = prime[1] = 0;
    for (ll i = 2; i * i < Psize; i++) {
        if (prime[i] == 1) {
            // cout << "i: " << i << endl;
            for (ll j = i * i; j < Psize; j += i) {
                // cout << j << endl;
                prime[j] = 0;
            }
        }
    }
    /*for (int i = 0; i < prime.size(); i++) {
        if (prime[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;*/
    int i = 0;
    for (int sum = 0; sum < k; sum += prime[i]) {i++;}
    cout << i << endl;
    return 0;
}