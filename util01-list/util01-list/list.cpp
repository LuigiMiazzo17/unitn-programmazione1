//
//  list.cpp
//  util01-list
//
//  Created by Luigi Miazzo on 21/02/22.
//

#include "list.hpp"
#include <iostream>

//----------------------------------------------------------------------------------------list

list list::init(){
    list l;
    l.fNode = nullptr;
    return l;
}

int list::listLen(){
    if(this->fNode == nullptr)
        return 0;
    int c = 1;
    listNode * currNode = this->fNode;
    while(currNode->nextNode != nullptr){
        currNode = currNode->nextNode;
        c++;
    }
    return c;
}

bool list::addAt(int value, int at){
    if(at > 0 && at < this->listLen()){
        listNode * prevNode = this->fNode;
        for(int i = 0; i < at - 1; i++){
            prevNode = prevNode->nextNode;
        }
        prevNode->nextNode = new listNode{value, prevNode->nextNode};
        return true;
    }
    else if(at == 0){
        this->fNode = new listNode{value, this->fNode};
        return true;
    }
    if(at == this->listLen()){
        this->append(value);
        return true;
    }
    return false;
}

bool list::removeAt(int at){
    if(at > 0 && at < this->listLen() - 1){
        listNode * prevNode = this->fNode;
        for(int i = 0; i < at - 1; i++){
            prevNode = prevNode->nextNode;
        }
        listNode * tempNode = prevNode->nextNode;
        prevNode->nextNode = tempNode->nextNode;
        delete tempNode;
        return true;
    }
    else if(at == 0){
        if(this->fNode == nullptr)
            return false;
        listNode * tempNode = this->fNode;
        this->fNode = this->fNode->nextNode;
        delete tempNode;
        return true;
    }
    if(at == this->listLen() - 1){
        listNode * currNode = this->fNode;
        while(currNode->nextNode->nextNode != nullptr){
            currNode = currNode->nextNode;
        }
        delete currNode->nextNode;
        currNode->nextNode = nullptr;
        return true;
    }
    return false;
        
}

void list::append(int value){
    if(this->fNode == nullptr){
        this->fNode = new listNode{value, nullptr};
        return;
    }
    listNode * currNode = this->fNode;
    while(currNode->nextNode != nullptr){
        currNode = currNode->nextNode;
    }
    currNode->nextNode = new listNode{value, nullptr};
}

bool list::elementAt(int &value, int at){
    if(at >= 0 && at < this->listLen()){
        listNode * currNode = this->fNode;
        for(int i = 0; i < at; i++)
            currNode = currNode->nextNode;
        value = currNode->value;
        return true;
    }
    return false;
}

void list::deleteList(){
    while(this->removeAt(0));
}

void list::printList(){
    listNode * currNode = this->fNode;
    while(currNode != nullptr){
        std::cout << currNode->value << ", ";
        currNode = currNode->nextNode;
    }
}

//----------------------------------------------------------------------------------------stack

void stack::init(){
    this->_stack = new list;
    *(this->_stack) = list::init();
}

void stack::push(int value){
    this->_stack->append(value);
}

bool stack::top(int& value){
    return this->_stack->elementAt(value, this->_stack->listLen() - 1);
}

bool stack::pop(){
    return this->_stack->removeAt(this->_stack->listLen() - 1);
}

void stack::deinit(){
    this->_stack->deleteList();
}

//----------------------------------------------------------------------------------------queue

void queue::init(){
    this->_queue = new list;
    *(this->_queue) = list::init();
}

bool queue::first(int& value){
    return this->_queue->elementAt(value, this->_queue->listLen() - 1);
}

void queue::enqueue(int value){
    this->_queue->addAt(value, 0);
}

bool queue::dequeue(){
    return this->_queue->removeAt(this->_queue->listLen() - 1);
}

void queue::deinit(){
    this->_queue->deleteList();
}
