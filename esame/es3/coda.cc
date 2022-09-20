// Inserisci qui il codice implementazione delle funzioni in coda.h

#include <iostream>

//----------------------------------------------------------------------------------------dichiarazioni

struct listNode;
struct list;
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
    void printListR();
    static void printListR_aux(listNode *);
};

struct queue{
    list * _queue;
    
    void init();
    void enqueue(int);
    bool first(int&);
    bool dequeue();
    void deinit();
};

//-------------------------------------------------------------------------------------------------implementazioni coda.h

static queue qArr[2];

//qArr[0] = s1
//qArr[1] = s2

// inizializza la coda e altri valori rilevanti, se necessario
void init(){
    qArr[0].init();
    qArr[1].init();
}

// inserimento di un elemento nella sotto-coda con meno elementi
bool enqueue(int n){
    int q1Len = qArr[0]._queue->listLen();
    int q2Len = qArr[1]._queue->listLen();

    if(q1Len + q2Len == 11)
        return false;

    if(q1Len <= q2Len)
        qArr[0].enqueue(n);
    else
        qArr[1].enqueue(n);
    return true;
}

// assegna al parametro (passato per riferimento) il valore del primo elemento della sotto-coda del primo sportello
bool firstS1(int& n){
   return qArr[0].first(n);
}

// assegna al parametro (passato per riferimento) il valore del primo elemento della sotto-coda del secondo sportello
bool firstS2(int& n){
    return qArr[1].first(n);
}

// rimuove il primo elemento della sotto-coda del primo sportello
bool dequeueS1(){
    return qArr[0].dequeue();
}

// rimuove il primo elemento della sotto-coda del secondo sportello
bool dequeueS2(){
    return qArr[1].dequeue();
}

// de-inizializza la coda e dealloca eventuale memoria dinamica, se necessario
void deinit(){
    qArr[0].deinit();
    qArr[1].deinit();
}

// stampa a video tutti gli elementi delle due sotto-code
void print(){
    std::cout << "s1: ";
    qArr[0]._queue->printListR();
    std::cout << std::endl << "s2: ";
    qArr[1]._queue->printListR();
    std::cout << std::endl;
}

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
    delete this;
}

void list::printList(){
    listNode * currNode = this->fNode;
    while(currNode != nullptr){
        std::cout << currNode->value << " ";
        currNode = currNode->nextNode;
    }
}

void list::printListR(){
    if(this->fNode != nullptr)
        printListR_aux(this->fNode);
}

void list::printListR_aux(listNode * node){
    if(node->nextNode == nullptr){
        std::cout << node->value << " ";
        return;
    }
    printListR_aux(node->nextNode);
    std::cout << node->value << " ";    
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