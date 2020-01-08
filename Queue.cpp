#ifndef QUEUE_CPP
#define QUEUE_CPP
/******************************************************************************

                            QUEUE (by: Truc Tran)

*******************************************************************************/
#include <iostream>
using namespace std;
#include "DoublyLinkedList.cpp"

/*
Queue<type> functions:
- void push_bottom(type elem)
- type pop_top()
- int size()
*/
template <typename T>
class Queue{
private:
    LinkedList<T> thelist;

public:
    void push_bottom(T elem){
        thelist.addBack(elem);
    }
   
    T pop_top(){
       return thelist.pop_front();
    }
   
    int size(){
        return thelist.length();
    }
    
};

#endif