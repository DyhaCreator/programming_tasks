#include <iostream>
#include <cmath>

int main(){
    long long ans = 0;
    int P, Q;
    std::cin >> P >> Q;

    int l = 1;
    while(l <= Q){
        l = l << 1;
        ans += round((float)Q / (float)l) * (l - 1);
        //std::cout << l-1 << " " << round((float)Q / (float)l) << " " << round((float)Q / (float)l) * (l - 1) << std::endl;
    }
    //std::cout << ans << std::endl;

    Q = P - 1;
    int ans2 = 0;
    l = 1;
    while(l <= Q){
        l = l << 1;
        ans2 += round((float)Q / (float)l) * (l - 1);
        //std::cout << l-1 << " " << round((float)Q / (float)l) << " " << round((float)Q / (float)l) * (l - 1) << std::endl;
    }

    std::cout << ans - ans2 << std::endl;
    return 0;
}