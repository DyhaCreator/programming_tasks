#include <iostream>
#include <vector>

using namespace std;

int count_cows(vector<int>a, int size, int n){
    int last = 0, ans = 0;
    for (int i = 0; i < size - 1; i++){
        if(a[i] - a[last] < n){
            ans ++;
            last = i;
            cout << last << endl;
        }
    }
    return ans;
}

int main(){
    int n, c;
    cin >> n >> c;
    vector<int>a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < (a[n - 1] - a[0]); i++) {
        if (count_cows(a, n, i) == c) {
            break;
        }
    }
    return 0;
}