#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for (ll &x : a)
        cin >> x;
    // как дела?


    ll ans = a[0];
	ll ans_l = 0;
    ll ans_r = 0;
	ll sum = 0;
    ll min_sum = 0;
	ll min_pos = -1;
    for (ll r = 0; r < n; ++r) {
	    sum += a[r];
	    ll cur = sum - min_sum;
	    if (cur > ans) {
		    ans = cur;
		    ans_l = min_pos + 1;
		    ans_r = r;
	    }
	    if (sum <= min_sum) {
		    min_sum = sum;
		    min_pos = r;
	    }
    }
    cout << ans_l + 1 << endl << ans_r + 1 << endl;
    return 0;
}