#include <iostream>
#include <vector>

int main(){
    std::vector<int>indexes = std::vector<int>();
    int a[1000];
    int N, x;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> a[i];
    }
    std::cin >> x;
    for(int i = 0; i < N; i++){
        if(a[i] == x){
            indexes.push_back(i);
        }
    }
    for(int i = 0; i < indexes.size(); i++){
        std::cout << indexes[i] + 1 << " ";
    }
    std::cout << std::endl;
    return 0;
}