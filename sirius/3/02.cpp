#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> prime;

bool isPrime(int n) {
    for (auto &x : prime)
        if (n % x == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime(i)) prime.push_back(i);
    }
    

    /*for (auto &x : prime)
        cout << x << " ";
    cout << endl;*/

    vector<int> n_prime;

    for (int nums = 2; nums <= n; nums++) {
        int index = 0;
        int save_nums = nums;

        while (nums > 1 && index < prime.size()) {
            // cout << nums << " " << prime[index] << endl;
            if (nums % prime[index] == 0) {
                nums /= prime[index];
                n_prime.push_back(prime[index]);
            } else {
                index++;
            }
        }

        if (nums > 1) n_prime.push_back(nums);

        nums = save_nums;
    }

    /*for (auto &x : n_prime)
        cout << x << " ";
    cout << endl;*/

    vector<int> prime_pow(50, 0);

    for (auto &x : n_prime)
        prime_pow[x]++;
    
    int ans = 1;
    for (auto &x : prime_pow) {
        ans *= x + 1;
    }
    cout << ans << endl;
    return 0;
}