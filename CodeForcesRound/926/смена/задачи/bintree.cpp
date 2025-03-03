#include<algorithm>
#include<iostream>
#include<vector>

struct node{
    int x;

    node* right;
    node* left;

    node(){}
    node(int val): x(val), right(nullptr){}

    void print(node *root){
        if(root != nullptr){
            std::cout << root -> x << std::endl;
            if(root -> left != nullptr){
                print(root -> left);
            }
            if(root -> right != nullptr){
                print(root -> right);
            }
        }
    }
};

int SecondMax(node* root){
    node *lastNode = nullptr;
    while(root -> right != nullptr){
        lastNode = root;
        root = root -> right;
    }
    if(root -> left != nullptr){
        return root -> left -> x;
    }
    return lastNode -> x;
}

int height(node* root)
{
    if (root == nullptr) {
        return 0;
    }

    return 1 + std::max(height(root->left), height(root->right));
}

node* add(node *root, node *obj){
    if(root == nullptr){
        return obj;
    }
    if(root -> x < obj -> x){
        if(root -> right == nullptr){
            root -> right = obj;
            return root;
        }
        else{
            add(root -> right, obj);
        }
    }
    else if(root -> x > obj -> x){
        if(root -> left == nullptr){
            root -> left = obj;
            return root;
        }
        else{
            add(root -> left, obj);
        }
    }
    return root;
}

void printLists(node *root){
    if(root -> left == nullptr && root -> right == nullptr){
        std::cout << root -> x << std::endl;
    }
    else{
        if(root -> left != nullptr){
            printLists(root -> left);
        }
        if(root -> right != nullptr){
            printLists(root -> right);
        }
    }
}
std::vector<int>r = std::vector<int>();
void printR(node *root){
    if(root -> left != nullptr && root -> right != nullptr){
        r.push_back(root -> x);
    }
    if(root -> left != nullptr){
        printR(root -> left);
    }
    if(root -> right != nullptr){
        printR(root -> right);
    }
}

void printV(node *root){
    if((root -> left != nullptr && root -> right == nullptr) || (root -> left == nullptr && root -> right != nullptr)){
        r.push_back(root -> x);
    }
    if(root -> left != nullptr){
        printV(root -> left);
    }
    if(root -> right != nullptr){
        printV(root -> right);
    }
}

bool balansed(node *root){
    if((height(root -> left) == 0 || height(root -> right) == 0) && abs(height(root -> left) - height(root -> right)) <= 1){
        return true;
    }
    if(abs(height(root -> left) - height(root -> right)) <= 1){
        return balansed(root -> left) && balansed(root -> right);
    }
    return false;
}

int main(){
    node *root = nullptr; 
    int num = 1;
    while(num != 0){
        std::cin >> num;
        if(num == 0){
            break;
        }
        root = add(root, new node(num));
    }

    //std::cout << abs(height(root -> left) - height(root -> right)) << std::endl;

    if(balansed(root)){
        std::cout << "YES" << std::endl;
    }
    else{
        std::cout << "NO" << std::endl;
    }

    return 0;
}
