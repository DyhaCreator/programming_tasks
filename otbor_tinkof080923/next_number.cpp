#include <iostream>

int main(){
    int a[1000];
    int N, x;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> a[i];
    }
    std::cin >> x;
    int ans = -5000;
    for(int i = 0; i < N; i++){
        if(abs(x - a[i]) < abs(x - ans)){
            ans = a[i];
        }
    }
    std::cout << ans << std::endl;
    return 0;
}