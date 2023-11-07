#include <iostream>
#include <cmath>
#define ll long long

ll min(ll a1, ll a2){
    if(a1 < a2){
        return a1;
    }
    return a2;
}
ll max(ll a1, ll a2){
    if(a1 > a2){
        return a1;
    }
    return a2;
}

int main(){
    ll a[100000];
    ll s[100000];
    ll pref[100000];
    ll suff[100000];
    ll n, k;
    std::cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = k; i <= n; i++) {
        pref[i] = max(pref[i - 1], s[i] - s[i - k]);
    }
    for (int i = n - k + 1; i >= 1; i--) {
        suff[i] = max(suff[i + 1], s[i + k - 1] - s[i - 1]);
    }
    ll best = 2e18;
    for (int i = 1; i <= n - k + 1; i++) {
        best = min(best, max(pref[i - 1], suff[i + k]));
    }
    std::cout << best << std::endl;

    return 0;
}
/*

10 2
1 2 4 5 2 4 2 2 1 6

*/