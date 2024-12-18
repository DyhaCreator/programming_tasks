#include<iostream>
#include<vector>
#include<cmath>

std::vector<int> tree = {0};

void Shift_Up(int index){
    while(tree[index] > tree[ceil((float)(index - 1) / 2.0)] && index > 1){
        int buffer = tree[index];
        tree[index] = tree[ceil((float)(index - 1) / 2.0)];
        tree[ceil((float)(index - 1) / 2.0)] = buffer;
        index = ceil((float)(index - 1) / 2.0);
    }
    //std::cout << index << std::endl;
}

void Shift_Down(int index){
    while(index * 2 < tree.size()){
        int right = index * 2 + 1;
        int left = index * 2;

        int j = left;
        if (right < tree.size() && tree[right] > tree[left]){
            j = right;
        }
        if(tree[index] >= tree[j]){
            break;
        }
        int buffer = tree[index];
        tree[index] = tree[j];
        tree[j] = buffer;
        index = j;
    }
    std::cout << index;
}

void ex(){
    int i = tree[1];
    tree[1] = tree[tree.size()-1];
    tree.pop_back();
    Shift_Down(1);
    std::cout << " " << i << std::endl;
}

int main(){
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        tree.push_back(a);
    }
    for(int i = 0; i < n - 1; i++){
        ex();
    }

    /*for(int i = 1; i < tree.size(); i++){
        std::cout << tree[i] << " ";
    }
    std::cout << std::endl;*/
    return 0;
}