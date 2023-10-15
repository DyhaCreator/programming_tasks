#include <iostream>
#include <string>

int main(){
    std::string str1, str2;
    std::cin >> str1 >> str2;
    if(str2.find(str1) != std::string::npos){
        std::cout << "yes" << std::endl;
    }
    else{
        std::cout << "no" << std::endl;
    }
    return 0;
}