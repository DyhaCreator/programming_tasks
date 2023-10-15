#include <iostream>
#include <string>


int main(){
    int n;
    std::cin >> n;
    std::string str1, str2;
    std::cin >> str1;
    for(int i = 0; i < n - 1; i++){
        std::cin >> str2;
        std::string str = "";
        for(int i = 0; i < str1.size(); i++){
            str += str2 + str1[i];
        }
        str1 = str + str2;
    }
    //std::cout << str1 << std::endl;
    int kras = 0;
    int max_kras = 0;
    for(int i = 0; i < str1.size(); i++){
        kras++;
        if(kras > max_kras){
            max_kras = kras;
        }
        if(str1[i] != str1[i + 1]){
            kras = 0;
        }
    }
    std::cout << max_kras << std::endl;
    return 0;
}