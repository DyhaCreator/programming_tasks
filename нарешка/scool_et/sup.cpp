#include <iostream>

int f(int a){
    int ans = 0;
    for(int i = 0; i < a + 1; i++){
        int s = 0;
        int b = i;
        while(b > 0){
            s += b % 10;
            b = b / 10;
        }
        if(s % 2 == 1){
            ans += 1;
        }
    }
    return ans;
}

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << f(b) - f(a - 1) << std::endl;
    return 0;
}