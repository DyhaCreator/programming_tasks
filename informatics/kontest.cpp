#include <iostream>
#include <string>
#include <vector>

int in(std::string str, std::vector<std::string>v){
    for(int i = 0; i < v.size(); i++){
        if(str == v[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    long long ans = 0;
    int N, M, D;
    std::cin >> N >> M;
    std::vector<std::string>n = std::vector<std::string>();
    std::vector<std::string>m = std::vector<std::string>();
    std::vector<int>d = std::vector<int>();
    for(int i = 0; i < N; i++){
        std::string a;
        std::cin >> a;
        n.push_back(a);
    }
    for(int i = 0; i < M; i++){
        std::string a;
        std::cin >> a;
        m.push_back(a);
    }
    std::cin >> D;
    for(int i = 0; i < M; i++){
        int a;
        std::cin >> a;
        d.push_back(a);
    }
    for(int i = 0; i < N; i++){
        int a = in(n[i], m);
        if(a != -1){
            ans += d[a];
        }
        else{
            ans += D;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}