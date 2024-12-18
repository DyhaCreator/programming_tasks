#include <iostream>

int main(){
    int a[100];
    int N;
    std::cin >> N;
    int min = 1e9, max = -1e9;
    for(int i = 0; i < N; i++){
        std::cin >> a[i];
        if(a[i] > max){
            max = a[i];
        }
        if(a[i] < min){
            min = a[i];
        }
    }
    for(int i = 0; i < N; i++){
        if(a[i] == max){
            a[i] = min;
        }
        std::cout << a[i] << " ";
    }

    return 0;
}