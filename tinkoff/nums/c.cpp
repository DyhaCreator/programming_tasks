#include <iostream>
#include <vector>
#include <map>
#include <set>
#define ll long long
using namespace std;

vector<int>prime = vector<int>();

bool isPrime(int n) {
    for (auto x : prime) {
        if (n % x == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    set<int>st;
    map<int, int>mp;
    int i = 0;
    while (n > 1) {
        while (i < int(prime.size()) && n % prime[i] != 0) {
            i++;
        }
        if (i == int(prime.size())) {
            st.insert(n);
            mp[n]++;
            break;
        }
        st.insert(prime[i]);
        mp[prime[i]]++;
        n /= prime[i];
    }
    int ans = 1;
    for (auto x : st) {
        ans *= (mp[x] + 1);
    }
    cout << ans << endl;
    return 0;
}