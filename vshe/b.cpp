using namespace std;
#include <iostream>

int main(){
    long long n, k, a, m, t;
    cin >> n >> k >> a>> m >> t;
    long long ans = 0;
    for(int i = n; i >= 1; i--){
        if(a * i + m + ans <= t){
            cout << "Yes";
            return 0;
        } else {
            ans += m * k;
        }
    }
    cout << "No";

}