#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int>ans = vector<int>();

void rec(int n, vector<int>a) {
    if (n == 0) {
        if (a.size() <= 4) {
            for (auto x : a) 
                cout << x << " ";
            cout << endl;
            exit(0);
        }
        return;
    }
    a.push_back(0);
    int i = 1;
    while (i * i <= n) {
        a[a.size() - 1] = i;
        rec(n - i * i, a);
        i++;
    }
}

int main() {
    int n;
    cin >> n;
    rec(n, vector<int>());
    return 0;
}