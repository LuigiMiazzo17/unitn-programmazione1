//
//  tree.cpp
//  util00-tree
//
//  Created by Luigi Miazzo on 21/02/22.
//

#include "tree.hpp"
#include <iostream>

bool node::isLeaf(){
    if(this->left == nullptr && this->right == nullptr)
        return true;
    return false;
}

void node::insert(int value){
    if(this->value < value){
        if(this->right == nullptr)
            this->right = new node{value, nullptr, nullptr};
        else
            this->right->insert(value);
    }
    else{
        if(this->left == nullptr)
            this->left = new node{value, nullptr, nullptr};
        else
            this->left->insert(value);
    }
}

void node::deleteNode(){
    if(this->left != nullptr)
        this->left->deleteNode();
    if(this->right != nullptr)
        this->right->deleteNode();
    delete this;
}

bool node::find(int value){
    if(this->value == value)
        return true;
    else if(this->left != nullptr && this->value >= value)
        return this->left->find(value);
    else if(this->right != nullptr && this->value <= value)
        return this->right->find(value);
    return false;
}

void node::printNode(int s){
    s++;
    
    if(this->right != nullptr)
        this->right->printNode(s);
        
    for(int i = 1; i < s; i++)
        std::cout << "\t";
    
    std::cout << this->value << "\n";
    
    if(this->left != nullptr)
        this->left->printNode(s);
    
}

void node::printSortedNode(){
    if(this->left != nullptr)
        this->left->printSortedNode();
    std::cout << this->value << ", ";
    if(this->right != nullptr)
        this->right->printSortedNode();
}

void node::search(int n){
    std::cout << this->value << ", ";
    if(this->value == n)
        return;
    else if(this->value > n){
        if(this->left != nullptr){
            std::cout << "sinistra, ";
            this->left->find(n);
        }
        else
            std::cout << "Not found!";
    }
    else if(this->value < n){
        if(this->right != nullptr){
            std::cout << "destra, ";
            this->right->find(n);
        }
        else
            std::cout << "Not found!";
    }
}

void node::getElements(int arr[], int &c){
    arr[c] = this->value;
    c++;
    if(this->left != nullptr)
        this->left->getElements(arr, c);
    if(this->right != nullptr)
        this->right->getElements(arr, c);
}

int node::countElements(){
    int c = 1;
    if(this->left != nullptr)
        c += this->left->countElements();
    if(this->right != nullptr)
        c += this->right->countElements();
    return c;
}

node* node::nodeBst(int arr[], int start, int end){
    node* cNode = nullptr;
    int m = (end + start)/2;
    if(end > start){
        cNode = new (std::nothrow) node;
        cNode->value = arr[m];
        cNode->left = nodeBst(arr, start, m);
        cNode->right = nodeBst(arr, m + 1, end);
    }
    
    return cNode;
}

//------------------------------------------------------------------------------------------------------tree

tree tree::createNewTree(){
    tree t;
    t.root = nullptr;
    return t;
}

bool tree::isEmpty(){
    if(this->root == nullptr)
        return true;
    return false;
}

void tree::insert(int value){
    if(this->root == nullptr)
        this->root = new node{value, nullptr, nullptr};
    else{
        this->root->insert(value);
    }
}

void tree::deleteTree(){
    if(this->root == nullptr)
        this->root->deleteNode();
}

bool tree::find(int value){
    if(this->root != nullptr)
        return this->root->find(value);
    return false;
}


void tree::printTree(){
    if(this->root != nullptr)
        this->root->printNode(0);
}

void tree::printSortedTree(){
    if(this->root != nullptr)
        this->root->printSortedNode();
}

void tree::search(int n){
    if(this->root->value == n){
        std::cout << "Il numero si trova nella radice dell'albero!" << std::endl;
        return;
    }
    if(this->root != nullptr){
        this->root->find(n);
        std::cout << std::endl;
    }
}

int * tree::getElements(int & len){
    len = this->countElements();
    if(len > 0){
        int * arr = new int[len];
        int c = 0;
        this->root->getElements(arr, c);
        return arr;
    }
    return new int[0];
}

int tree::countElements(){
    int c = 0;
    if(this->root != nullptr)
        c = this->root->countElements();
    return c;
}

tree tree::bst(int arr[], int len){
    tree t = tree::createNewTree();
    if(len > 0){
        bubbleSort(arr, len);
        t.root = node::nodeBst(arr, 0, len);
    }
    else
        t.root = nullptr;
    return t;
}

void tree::bst(){
    if(this->root != nullptr){
        int len = 0;
        int * arr = this->getElements(len);
        bubbleSort(arr, len);
        tree t = tree::bst(arr, len);
        this->deleteTree();
        this->root = t.root;
        delete [] arr;
    }
}

//------------------------------------------------------------------------------------------------------bubbleSort

void bubbleSort(int arr[], int len) {
    for (int i = len - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}
