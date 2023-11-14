#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int numk;
    cin >> numk;
    for (int n = 1; n < numk; n++) {
        int num = n;
        vector<int>ans = vector<int>();
    while (num > 0) {
        int n = 2;
        while (n * n <= num) {
            n++;
        }
        n--;
        ans.push_back(n);
        num -= n * n;
        //cout << n << " " << num << endl;
    }
    if (ans.size() > 4) {
        cout << n << " ";
    for (auto x : ans) 
        cout << x << " ";
    cout << endl;
    }
    }
    return 0;
}