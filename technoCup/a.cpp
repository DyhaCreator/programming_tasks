#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>>a = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int n1;
        cin >> n1;
        vector<int>a1 = vector<int>(n1);
        for (auto &x : a1)
            cin >> x;
        a[i] = a1;
    }
    
    return 0;
}