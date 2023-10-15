#include <iostream>

int main(){
    //я не думаю что это правильное решение просто интересно
    int n;
    std::cin >> n;
    if(n < 3){
        std::cout << n << std::endl;
        return 0;
    }
    std::cout << n * ((n - 1) / 2) * 2 << std::endl;
    return 0;
}