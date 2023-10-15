#include <iostream>

int main(){
    int a[1000];
    int N;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> a[i];
    }
    int min = 0, lastMin = 0;
    for(int i = 0; i < N; i++){
        if(a[i] <= a[min]){
            min = i;
        }
    }
    for(int i = 0; i < N; i++){
        if(a[i] < a[lastMin] && i != min){
            lastMin = i;
        }
    }
    std::cout << a[min] << " " << a[lastMin] << std::endl;
    return 0;
}