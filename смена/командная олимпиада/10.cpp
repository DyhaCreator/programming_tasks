#include <iostream>
#include <vector>

int main(){
    int sx, n;
    std::cin >> sx >> n;
    std::vector<int>pol = std::vector<int>();
    pol.resize(sx * sx, 0);
    for(int i = 0; i < n; i++){
        int x, y;
        std::cin >> x >> y;
        x -= 1;
        y -= 1;
        pol[x + y * sx] = 1;
        if(x + 1 < sx && y - 2 >= 0)
            pol[(x + 1) + (y - 2) * sx] = 1;
        if(x + 2 < sx && y - 1 >= 0)
            pol[(x + 2) + (y - 1) * sx] = 1;
        if(x + 2 < sx && y + 1 < sx)
            pol[(x + 2) + (y + 1) * sx] = 1;
        if(x + 1 < sx && y + 2 < sx)
            pol[(x + 1) + (y + 2) * sx] = 1;
        if(x - 1 >= 0 && y + 2 < sx)
            pol[(x - 1) + (y + 2) * sx] = 1;
        if(x - 2 >= 0 && y + 1 < sx)
            pol[(x - 2) + (y + 1) * sx] = 1;
        if(x - 2 >= 0 && y - 1 >= 0)
            pol[(x - 2) + (y - 1) * sx] = 1;
        if(x - 1 >= 0 && y - 2 >= 0)
            pol[(x - 1) + (y - 2) * sx] = 1;
    }
    int ans = 0;
    for(int i = 0; i < pol.size(); i++){
        if(pol[i] == 0){
            ans ++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}