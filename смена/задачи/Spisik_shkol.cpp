#include <cstdio>
#include <vector>

int main(){
    std::vector<int>vec = std::vector<int>();
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char name[100];
        scanf("%s" &name);
        int a = 0;
        for(int j = 0; j < 110; j++){
            if(name[j] > 47 && name[j] < 58){
                a = (a * 10) + name[j] - 48;
            }
        }
        vec.push_back(a);
    }
    for(int i = 0; i < vec.size(); i++){
        printf("%d\n", vec[i]);
    }
    return 0;
}