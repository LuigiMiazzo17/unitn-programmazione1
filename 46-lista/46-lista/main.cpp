//
//  main.cpp
//  46-lista
//
//  Created by Luigi Miazzo on 19/02/22.
//

#include <iostream>
#include <fstream>

using namespace std;

struct node;
typedef node* list;
struct node{
    int value;
    list next;
};

list getData(const char[]);
void printList(list);
void printInvertedList(list);
void destroyList(list);

int main(int argc, const char * argv[]) {
    
    list l = getData("input.txt");
    cout << "Lista richiesta: " << endl;
    printList(l);
    cout << "Lista richiesta: " << endl;
    printInvertedList(l);
    destroyList(l);
    
    cout << endl;
    return 0;
}

list getData(const char fname[]){
    fstream file;
    file.open(fname, ios::in);
    
    if(file.fail()){
        cout << "Something went wrong! " << endl;
        return NULL;
    }
    
    int buff;
    file >> buff;
    
    list lista = new node{buff, NULL};
    node * currentNode = lista;
    
    while(file >> buff){
        node* newNode = new node{buff, NULL};
        currentNode->next = newNode;
        currentNode = newNode;
    }
    
    file.close();
    return lista;
}

void printList(list l){
    node * currentNode = l;
    while(currentNode->next != NULL){
        cout << currentNode->value << ", ";
        currentNode = currentNode->next;
    }
    cout << currentNode->value << endl;
    
    return;
}

void printInvertedList(list l){
    if(l->next == NULL){
        cout << l->value << ", ";
        return;
    }
    printInvertedList(l->next);
    cout << l->value << ", ";
    return;
}

void destroyList(list l){
    node * currentNode = l;
    while(currentNode->next != NULL){
        node * nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    delete currentNode;
}
