#include <iostream>

int main(){
    int n1, n2;
    std::cin >> n1 >> n2;
    if(n1 == 6)n1 = 9;
    if(n2 == 6)n2 = 9;
    if(n1 > n2)std::cout << n1 << n2 << std::endl;
    else{std::cout << n2 << n1 << std::endl;}   
    return 0;
}