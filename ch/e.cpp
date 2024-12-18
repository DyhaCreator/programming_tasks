using namespace std; 
#include <random> 
#include <iostream> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <string> 
 
using ll = long long; 
using vll = vector<long long>; 
 
int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    ll n, m; 
    cin >> n; 
    vll data(n + 1); 
    for (int i = 0; i < n; i++) { 
        cin >> data[i]; 
        data[i] += 7; 
    } 
    data[n] = 1e18; 
    sort(data.begin(), data.end()); 
    cin >> m; 
     
    for (int i = 0; i < m; i++) { 
        ll a; 
        cin >> a; 
        ll k = *(upper_bound(data.begin(), data.end(), a)); 
        if (k - a <= 7) { 
            cout << "Yes" << "\n"; 
        } 
        else { 
            cout << "No" << "\n"; 
        } 
    } 
    return 0; 
}