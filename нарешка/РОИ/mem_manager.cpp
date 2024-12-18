#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>>mem = std::vector<std::vector<int>>();
    mem.push_back({0, 0, 0});
    for(int i = 0; i < m; i++){
        int a;
        std::cin >> a;
        if(a >= 0){
            int index = -1;
            for(int j = 0; j < mem.size() - 1; j++){
                int endIndex = mem[j][0] + mem[j][1];
                int startIndex = mem[j + 1][0];
                if(startIndex - endIndex >= a){
                    index = endIndex;
                }
            }
            if(index == -1){
                index = mem[mem.size() - 1][0] + mem[mem.size() - 1][1];
            }
            if(index + a > n){
                std::cout << -1 << std::endl;
            }
            else{
                std::cout << index + 1 << std::endl;
                mem.push_back({index, a, i + 1});
                std::sort(mem.begin(), mem.end());
            }
        }
        else{
            int index = -1;
            for(int j = 0; j < mem.size(); j++){
                if(mem[j][2] == -a){
                    index = j;
                    break;
                }
            }
            if(index != -1){
                mem.erase(mem.begin() + index);
            }
        }
        /*for(int j = 0; j < mem.size(); j++){
            std::cout << mem[j][0] << " " << mem[j][1] << " " << mem[j][2] << std::endl;
        }*/
    }
    return 0;
}