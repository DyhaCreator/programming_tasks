#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

vector<int> prime;
vector<int> del;
vector<int> pows;
int min_ans = INF;
int n;

bool isPrime(int n) {
    for (auto &x : prime)
        if (n % x == 0) return 0;
    return 1;
}

ll nsn(ll n) {
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= n;
        if (ans >= INF) return INF;
    }
    return ans;
}

int f(int index, int num) {
    if (index >= del.size()) {
        int snt = nsn(num);
        if (snt >= n) {
            min_ans = min(min_ans, num);
        }
        // cout << num << endl;
        return 0;
    }
    for (int i = 1; i <= pows[index]; i++) {
        num *= del[index];
        f(index + 1, num);
    }
    return 0;
}

int main() {
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (isPrime(i)) prime.push_back(i);
    }
    int save_n = n;
    int index = 0;
    while (n > 1 && index < prime.size()) {
        if (n % prime[index] == 0) {
            if (del.size() > 0 && del.back() == prime[index]) {
                pows[pows.size() - 1]++;
            } else {
                del.push_back(prime[index]);
                pows.push_back(1);
            }
            n /= prime[index];
        } else {
            index++;
        }
    }
    if (n > 1) {
        del.push_back(n);
        pows.push_back(1);
    }
    /*for (auto &x : del)
        cout << x << " ";
    cout << endl;
    for (auto &x : pows)
        cout << x << " ";
    cout << endl;*/
    n = save_n;
    f(0, 1);
    cout << min_ans << endl;
    
    return 0;
}