#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll>vec = vector<ll>(n + 1);
    for (int i = 1; i < n + 1; i++) {
        int x;
        cin >> x;
        vec[i] = vec[i - 1] + x;
        //cout << vec[i] << " ";
    }
    //cout << endl;
    int l = 1;
    int r = 1;
    ll max_sum = vec[r] - vec[l - 1];
    for (int i = 1; i < n + 1; i++) {
        for (int j = i; j < n + 1; j++) {
            ll sum = vec[j] - vec[i - 1];
            if (sum > max_sum) {
                max_sum = sum;
                l = i;
                r = j;
            } else if (sum == max_sum && (j < r || i > l)) {
                max_sum = sum;
                l = i;
                r = j;
            }
            //cout << sum << " " << i << ' ' << j << ' ' << max_sum << " " << l << " " << r << endl;
        }
    }
    cout << l << ' ' << r << ' ' << max_sum << endl;
    return 0;
}