#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<long long>plot = std::vector<long long>();
    long long N, M;
    std::cin >> N >> M;
    for(long long i = 0; i < N * M; i++){
        long long a;
        std::cin >> a;
        plot.push_back(a);
    }
    std::vector<long long>mesk = std::vector<long long>();
    long long n;
    std::cin >> n;
    for(long long i = 0; i < n; i++){
        long long a;
        std::cin >> a;
        mesk.push_back(a);
    }
    std::sort(mesk.begin(), mesk.end());
    std::sort(plot.begin(), plot.end());
    long long j = 0;
    for(long long i = 0; i < plot.size(); i++){
        if(j >= mesk.size())break;
        if(plot[i] >= mesk[j]){
            j++;
        }
    }
    std::cout << j << std::endl;
    return 0;
}