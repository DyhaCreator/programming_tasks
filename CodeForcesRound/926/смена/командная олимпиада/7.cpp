#include <iostream>
#include <vector>

int main(){
    int time = 0;
    int n, x, myx = 0;
    std::cin >> n >> x;
    int lastX = 0;
    for(int i = 0; i < n; i++){
        int x, r, g;
        std::cin >> x >> r >> g;
        myx += x - lastX;
        time += x - lastX;
        if(time % (r + g) < r){
            time += r - time % (r + g);
        }
        lastX = x;
    }
    std::cout << time + (x - lastX) << std::endl;
    return 0;
}