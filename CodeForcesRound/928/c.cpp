#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int sss(int a, int n, int k) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a + (i * k);
    }
    return ans;
}

int f(int n) {
    vector<int> count(4);
    vector<int> mmm = {13500, 900, 45, 1};
    vector<int> nnn = {1000, 100, 10, 1};
    int index = 0;
    while (n > 0) {
        count[index] = n % 10;
        n /= 10;
        index ++;
    }

    reverse(count.begin(), count.end());
    for (auto &x : count)
        cout << x << " ";
    cout << endl;

    int sum = 0;
    int ans = 0;

    for (int i = 0; i < count.size(); i++) {
        ans += sss(mmm[i] + sum * nnn[i], count[i], nnn[i]);
        cout << mmm[i] + sum * nnn[i] << endl;
        sum += count[i];
        cout << ans << endl;
        cout << sum << endl;
    }
    /*ans += (900 + 900 + (100 * (count[0] - 1))) / 2 * count[0];
    sum += count[0];
    cout << ans << endl;
    cout << sum << endl;
    ans += (45 + sum + 45 + sum + (10 * (count[1] - 1))) / 2 * count[1];
    sum += count[1];
    cout << ans << endl;
    cout << sum << endl;*/

    //ans += (0 + sum + 0 + sum + (1 * (count[2]))) / 2 * (count[2] + 1);
    cout << ans << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}

/*

1
45
900
13500
185000
2350000

*/