#include <iostream>
#include <cmath>

int main(){
    int n, t;
    std::cin >> n;
    if(n == 2 || n == 3){
        std::cout << "-1" << std::endl;
        return 0;
    }
    while(n > 8){
        n -= 5;
        t ++;
    }
    if(n < 7){
        std::cout << t + 1 << std::endl;
    }
    else if(n < 9){
        std::cout << t + 2 << std::endl;
    }
    return 0;
}