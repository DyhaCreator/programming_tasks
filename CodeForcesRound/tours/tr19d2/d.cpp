#include<iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string a, b;
    getline(cin, a);
    getline(cin, a);
    getline(cin, b);
    int flag = 0;
    for (auto i : a){
        if (i == '*'){
            flag = 1;
            break;
        }
    }
    if(n - flag > m){
        cout << "NO";
        return 0;
    }
    if(flag == 0 && n!=m){
        cout << "NO";
        return 0;
    }
    int i = 0;
    while(a[i]!='*' && i < n){
        if(a[i]!=b[i]){
            cout << "NO";
            return 0;
        }
        i++;
    }
    i = 1;
    while(a[n-i]!='*' && n - i >= 0){
        if(a[n - i]!= b[m - i]){
            cout << "NO";
            return 0;
        }
        i++;
    }
    cout << "YES";
    return 0;
}