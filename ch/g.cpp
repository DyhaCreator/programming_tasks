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
    ll n; 
    cin >> n; 
    for (int i = 0; i < n; i++) { 
        ll a; 
        cin >> a; 
        ll ost; 
        ll kol; 
        kol = a / 7; 
        ost = a - kol * 7; 
        if (ost == 1) { 
            if (kol >= 3) { 
                cout << "Yes\n"; 
            } 
            else { 
                cout << "No\n"; 
            } 
        } 
        else if (ost == 2) { 
            if (kol >= 4) { 
                cout << "Yes\n"; 
            } 
            else { 
                cout << "No\n"; 
            } 
        } 
        else if (ost == 3) { 
            if (kol >= 3) { 
                cout << "Yes\n"; 
            } 
            else { 
                cout << "No\n"; 
            } 
        } 
        else if (ost == 4) { 
            if (kol >= 1) { 
                cout << "Yes\n"; 
            } 
            else { 
                cout << "No\n"; 
            } 
        } 
        else if (ost == 5) { 
            if (kol >= 2) { 
                cout << "Yes\n"; 
            } 
            else { 
                cout << "No\n"; 
            } 
        } 
        else if (ost == 6) { 
            if (kol >= 1) { 
                cout << "Yes\n"; 
            } 
            else { 
                cout << "No\n"; 
            } 
        } 
        else if (ost == 0) { 
            cout << "Yes\n"; 
        } 
    } 
    return 0; 
}