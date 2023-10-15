#include <iostream>

int main(){
    int a[1000];
    int N;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> a[i];
    }
    int max = 0;
    for(int i = 0; i < N; i++){
        if(a[i] > a[max]){
            max = i;
        }
    }
    long long lmax = -1e10;
    for(int i = 0; i < N; i++){
        if(a[i] < a[max] && a[i] > lmax){
            lmax = a[i];
        }
    }
    std::cout << lmax << std::endl;
    return 0;
}