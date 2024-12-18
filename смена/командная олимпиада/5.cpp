#include <iostream>
#include <string>

int main(){
    int n;
    int a = 0, b = 0, sca = 0, scb = 0;
    std::cin >> n;
    std::string str;
    std::cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'A'){
            a++;
        }
        if(str[i] == 'B'){
            b++;
        }
        if(sca + scb >= 2){
            if(a >= 15 && (a - b) >= 2){
                sca++;
                break;
            }
            if(b >= 15 && ((b - a) >= 2)){
                scb++;
                break;
            }
        }
        if(a >= 25 && ((a - b) >= 2)){
            sca++;
            a = 0;
            b = 0;
        }
        if(b >= 25 && ((b - a) >= 2)){
            scb++;
            a = 0;
            b = 0;
        }
        //std::cout << a << " " << b << " " << b - a <<std::endl;
    }
    std::cout <<sca << " " << scb << std::endl;
    return 0;
}
//BABABABABABABABABABABABABABABABABABABABABABABABABABBBABABABABABABABABABABABABABABABABABABABABABABABABABB