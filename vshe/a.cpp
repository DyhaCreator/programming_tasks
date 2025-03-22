#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a%2==0){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    if(cnt1%2==0 && cnt2%2==0){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
    return 0;
}