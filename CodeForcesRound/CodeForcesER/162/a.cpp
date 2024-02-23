#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
#define prvec(vec) for(auto &x:vec)cout<<x<<" ";cout<<endl;
#define all(vec) vec.begin(),vec.end()
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (auto &x : vec)
            cin >> x;
        int findex = 0;
        int eindex = -1;
        while (vec[findex] == 0) {
            findex++;
        }
        for (int j = 0; j < n; j++) {
            if (vec[j] == 1) {
                eindex = j;
            }
        }
        int ans = 0;
        for (int j = findex; j < eindex; j++) {
            if (vec[j] == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}