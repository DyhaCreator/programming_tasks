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
    vector<string> st(4); 
    map<char, ll> mp = { {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'0', 0} }; 
    for (int i = 0; i < 4; i++) { 
        cin >> st[i]; 
    } 
    for (int i = 0; i < 4; i++) { 
        if (st[i].size() != 4) { 
            cout << "No"; 
            return 0; 
        } 
        for (int j = 0; j < st[i].size(); j++) { 
            if (mp[st[i][j]] % 2 == j % 2) { 
                cout << "No"; 
                return 0; 
             } 
        } 
    } 
    cout << "Yes"; 
    return 0; 
}