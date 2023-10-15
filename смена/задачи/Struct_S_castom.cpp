#include <iostream>
#include <vector>

struct SMnoj{
    std::vector<int>S = std::vector<int>();

    SMnoj(){}

    void add(int num){
        for(int i = 0; i < S.size(); i++){
            if(S[i] == num){
                return;
            }
        }
        S.push_back(num);
    }
    int next(int num){
        int min = 1e9 + 1;
        for(int i = 0; i < S.size(); i++){
            if(min > S[i] && S[i] >= num){
                min = S[i];
            }
        }
        if(min == 1000000001){
            return -1;
        }
        return min;
    }
};

int main(){
    SMnoj *mnoj = new SMnoj();
    int n;
    std::cin >> n;
    char d, lastD;
    int num;
    int y = 0;

    for(int i = 0; i < n; i++){
        std::cin >> d >> num;
        if(d == '+' && (i == 0 || lastD == '+')){
            mnoj -> add(num);
        }
        else if(d == '?'){
            y = mnoj -> next(num);
            std::cout << y << std::endl;
        }
        else if(d == '+' && lastD == '?'){
            mnoj -> add((num + y) % 1000000000);
        }
        lastD = d;
    }
    return 0;
}