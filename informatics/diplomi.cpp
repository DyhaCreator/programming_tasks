#include <iostream>

int main(){
    int n, w, h, x, y;
    std::cin >> w >> h >> n;
    int l = std::max(w, h);
    int r = std::max(w, h) * n;
    while(r - l > 1){
        int m = (l + r) / 2;
        if((m / w) * (m / h) >= n){
            r = m;
        }
        else{
            l = m;
        }
    }
    std::cout << r << std::endl;
    return 0;
}