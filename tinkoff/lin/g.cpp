#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n;

ll min(ll a, ll b) {
    if (a < b) {
        return a;
    }
    return b;
}

int max_ind(vector<int>a) {
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[maxi]) {
            maxi = i;
        }
    }
    return maxi;
}

int main() {
    cin >> n;
    vector<int>a = vector<int>();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    return 0;
}