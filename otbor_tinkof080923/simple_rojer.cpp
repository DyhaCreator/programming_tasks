#include <iostream>

int main(){
    long long ans = 0;
    int P, Q;
    std::cin >> P >> Q;

    for(int x = P; x <= Q; x++){
        ans += x ^ (x - 1);
        //std::cout << (x ^ (x - 1)) << std::endl;
    }

    std::cout << ans << std::endl;
    return 0;
}