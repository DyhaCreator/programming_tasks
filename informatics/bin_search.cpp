#include <iostream>

int main(){
    int a[100000];
    int N, K;
    std::cin >> N >> K;
    for(int i = 0; i < N; i++){
        std::cin >> a[i];
    }
    int l = 0, r = N;
    for(int i = 0; i < K; i++){
        int x = 0;
        std::cin >> x;
        if(x >= a[0] && x <= a[N - 1]){
            l = 0;
            r = N;
            while(l < r){
                int m = (l + r) / 2;
                if(x > a[m])l=m+1;
                else r=m;
            }
            //std::cout << a[l] << std::endl;
            if(a[r] == x){
                std::cout << "YES" << std::endl;
            }
            else{
                std::cout << "NO" << std::endl;
            }
        }
        else{
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}