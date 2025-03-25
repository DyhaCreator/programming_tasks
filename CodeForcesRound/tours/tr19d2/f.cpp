using namespace std;
#include <iostream>
#include <map>
#include<vector>
using ll = long long;

int main(){
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> v(2*1e5 + 2);
    for(int i = 0; i < n ;i++){
        ll a, b;
        cin >> a>> b;
        v[a]++;
        v[b+ 1]--;
    }
    vector<ll> pref(2 * 1e5 + 3);
    for(int i = 1 ; i <2 * 1e5 + 2 ;i++){
        pref[i] = pref[i - 1] + v[i];
    }
    vector<ll> otv(2 * 1e5 + 3);
    for(int i = 1; i< 2 * 1e5 + 2; i++){
        if(pref[i] >= k){
            otv[i]++; 
        }
        otv[i] += otv[i -1];
    }
    for(int i= 0;i <q; i++){
        ll l, r;
        cin >> l>> r;
        cout << otv[r] - otv[l -1] << "\n";
    }
}