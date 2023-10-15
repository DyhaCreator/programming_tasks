#include <iostream>
#include <vector>

int main(){
    std::vector<int>left = std::vector<int>();
    std::vector<int>right = std::vector<int>();
    int L, W;
    std::cin >> L >> W;
    int N, M;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        int a;
        std::cin >> a;
        left.push_back(a);
    }
    std::cin >> M;
    for(int i = 0; i < M; i++){
        int a;
        std::cin >> a;
        right.push_back(a);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::vector<int>size = std::vector<int>();
            int n0 = 
        }
    }
    return 0;
}