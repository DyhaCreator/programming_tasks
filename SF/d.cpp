#include <iostream>
#define ll long long
using namespace std;

int sum1(int num) {
    int ans = 0;
    while (num > 0) {
        if (num & 1 == 1) {
            ans += num % 10;
        }
        num /= 10;
    }
    return ans;
}

int sum2(int num) {
    int ans = 0;
    while (num > 0) {
        if (num & 1 == 0) {
            ans += num % 10;
        }
        num /= 10;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (abs(sum1(num) - sum2(num)) <= 1) {
            max = std::max(max, num);
        }
    }
    cout << max << endl;
    return 0;
}