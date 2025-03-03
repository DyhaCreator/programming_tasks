#include <iostream>
#include <vector>

int n, w;
std::vector<int>fir = std::vector<int>();
std::vector<int>sec = std::vector<int>();
std::vector<int>flow = std::vector<int>();

int sssr(int th){
    
}

int main(){
    std::cin >> n >> w;
    for(int i = 0; i < w; i++){
        int f, s;
        std::cin >> f >> s;
        fir.push_back(f);
        sec.push_back(s);
    }
    std::cout << sssr(0) << std::endl;
    return 0;
}