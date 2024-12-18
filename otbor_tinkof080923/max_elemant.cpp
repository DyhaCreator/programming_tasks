#include <iostream>

int main(){
    int N, x, max = -5000, maxIn = 0;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> x;
        if(x > max){
            max = x;
            maxIn = i;
        }
    }
    std::cout << maxIn + 1 << std::endl;
    return 0;
}