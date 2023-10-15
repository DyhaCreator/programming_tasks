#include <iostream>
#include <cmath>

int main(){
    int a, b, c, d;
    long long ans = 0;
    std::cin >> a >> b >> c >> d;

    for(int x = 1; x * x <= b; x++){
        int miny = std::max(x, std::max((a - 1) / x + 1, (c + 1) / 2 - x));
        int maxy = std::min(b / x, d / 2 - x);
        if(miny <= maxy){
            ans += (maxy - miny + 1);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}