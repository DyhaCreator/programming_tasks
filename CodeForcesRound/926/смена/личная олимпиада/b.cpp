#include <iostream>
#include <cmath>

int main(){
    unsigned long long w, h;
    std::cin >> w >> h;
    if(w == h){
        std::cout << w * h << std::endl;
        return 0;
    }
    unsigned long long rx = std::min(w, h);
    unsigned long long S = rx * rx;
    if(w >= h){
        w -= rx;
    }
    else{
        h -= rx;
    }
    if(w == h){
        std::cout << S + w * h << std::endl;
        return 0;
    }
    rx = std::min(w, h);
    S += rx * rx;
    std::cout << S <<std::endl;
    return 0;
    //как найти нод 3 - х чисел в с++
}