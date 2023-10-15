#include <iostream>
#include <cmath>

int min(long long a1, long long a2){
    if(a1 < a2){
        return a1;
    }
    return a2;
}

int main(){
    int a[100000];
    int s[100000];
    int pref[100000];
    int suff[100000];
    int n, k;
    std::cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    

    return 0;
}