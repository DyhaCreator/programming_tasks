#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int max = 0, lastMax = 0;
    for(int i = 0; i < n; i++){
        int num;
        std::cin >> num;
        if(num >= max){
            lastMax = max;
            max = num;
        }
        if(num < max && num > lastMax){
            lastMax = num;
        }
        if(i > 0){
            std::cout << lastMax << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}