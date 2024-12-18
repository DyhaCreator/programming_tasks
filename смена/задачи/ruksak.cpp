#include <iostream>
#include <vector>

int main(){
    std::vector<int>v = std::vector<int>();
    std::vector<int>s = std::vector<int>();
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        v.push_back(a);
    }
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        s.push_back(a);
    }
    
    return 0;
}