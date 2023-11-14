#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

void rec(int n, vector<int>ans) {
    if (n == 0) {
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
        return;
    }
    if (ans.size() > 4) {
        return;
    }
    int a = 0;
    while (a * a <= n) {
        
    }
}

int main() {
    int n;
    cin >> n;
    rec(n, vector<int>());
    return 0;
}