#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

vector<int>prime = vector<int>();

bool isPrime(int num) {
    for (int i = 0; i < prime.size(); i++) {
        if (num % prime[i] == 0) {
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
    vector<int>ans = vector<int>();
    while (n > 1) {
        int i = 0;
        while (i < prime.size() && n % prime[i] != 0) {
            i++;
        }
        if (i == prime.size()) {
            ans.push_back(n);
            break;
        } else {
            n /= prime[i];
            ans.push_back(prime[i]);
        }
    }
    int last = -1;
    int count = 0;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == last) {
            count++;
        } else if (last != -1) {
            cout << last << ((count == 1 || count == 0)?"":("^" + to_string(count))) << "*";
            last = ans[i];
            count = 1;
        } else {
            last = ans[i];
        }
    }
    cout << last << ((count == 1 || count == 0)?"":("^" + to_string(count))) << endl;
    return 0;
}