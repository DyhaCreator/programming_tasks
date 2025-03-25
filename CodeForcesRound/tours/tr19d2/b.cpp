using namespace std;
#include <iostream>
#include <map>

int main(){
    int t;
    cin >> t;
    while(t--){
        map<int, int> m;
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;
        m[a1 + a2]++;
        m[a4 - a2]++;
        m[a5 - a4]++;
        int ans = 0;
        for(auto i : m){
            ans = max(ans, i.second);
        }
        cout << ans <<"\n";
    }
    return 0;
}