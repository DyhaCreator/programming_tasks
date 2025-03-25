#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    ll t;
    cin >> t;
    while(t){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<int> pref(n+1);
    ll sum = 0;
    for(ll i = 0; i<n; i++){
        cin >> v[i];
        sum += v[i];
        pref[i + 1] = sum;
    }
    while(q){
        ll l, r, k;
        cin >> l >> r >> k;
        ll temp = 0;
        temp+=(r - l  + 1) * k;
        temp+=pref[l - 1];
        temp+=(pref[n] - pref[r]);
        if(temp%2 == 0){
            cout << "NO" << "\n";
        }
        else{
            cout << "Yes\n";
        }
        q--;
    }
    t--;
    }

}