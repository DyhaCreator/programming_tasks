#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int>arr = std::vector<int>();
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        arr.push_back(a);
    }
    int max = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > arr[max])
            max = i;
    }
    int a = arr[0];
    arr[0] = arr[max];
    arr[max] = a;
    for(int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";

    return 0;
}