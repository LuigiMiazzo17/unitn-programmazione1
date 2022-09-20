//
//  list.hpp
//  util01-list
//
//  Created by Luigi Miazzo on 21/02/22.
//

#ifndef list_hpp
#define list_hpp

struct listNode;
struct list;
struct stack;
struct queue;

struct listNode{
    int value;
    listNode * nextNode;
};

struct list{
    listNode * fNode;
    
    static list init();
    int listLen();
    bool addAt(int, int);
    void append(int);
    bool removeAt(int);
    bool elementAt(int&, int);
    void deleteList();
    void printList();
};

struct stack{
    list * _stack;
    
    void init();
    void push(int);
    bool top(int&);
    bool pop();
    void deinit();
};

struct queue{
    list * _queue;
    
    void init();
    void enqueue(int);
    bool first(int&);
    bool dequeue();
    void deinit();
};

#endif /* list_hpp */
