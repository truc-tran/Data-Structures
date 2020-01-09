#ifndef STACK_CPP
#define STACK_CPP
/******************************************************************************

                            STACK (by: Truc Tran)

*******************************************************************************/
#include <iostream>
using namespace std;
#include "DoublyLinkedList.cpp"

/*
Stack<type> functions:
- void push_top(type elem)
- type pop_top()
- int size()
*/
template <typename T>
class Stack{
private:
    LinkedList<T> thelist;

public:
    void push_top(T elem){
        thelist.addFront(elem);
    }
   
    T pop_top(){
       return thelist.pop_front();
    }
   
    int size(){
        return thelist.length();
    }
};


#endif
