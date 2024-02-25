#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#define ll long long
#define INF 1000000007
#define prvec(vec) for(auto &x:vec)cout<<x<<" ";cout<<endl;
#define all(vec) vec.begin(),vec.end()
using namespace std;

void solveA() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int s = 0;
        while (s < n && str[s] == 'W') {
            s++;
        }
        int f = n - 1;
        while (f >= s && str[f] == 'W') {
            f--;
        }

        cout << f - s + 1 << endl;
    }
}

void solveB() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        vector<int> count(26);
        for (int i = 0; i < n; i++) {
            int index = 0;
            while (index < 26 && count[index] != a[i]) {
                index++;
            }
            count[index]++;
            cout << char(index + 'a');
        }
        cout << endl;
    }
}

int main() {
    solveB();
    return 0;
}