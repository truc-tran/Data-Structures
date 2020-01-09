#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP

/******************************************************************************

                            Truc Tran

*******************************************************************************/
#include <iostream>
using namespace std;

template <typename T>
struct node{
     T data;
     node<T>* next;
     node<T>* prev;
};

template <typename T>
class LinkedList{
private:
    // Tail, head, size of Linklist
     node<T>* tail;
     node<T>* head;
     int size;

public:
     // Initialize the data in the node--EMPTY
     LinkedList(){
         tail = nullptr;
         head = nullptr;
         size = 0;
     }

     // Add node to the front of the list: creat node + assign header point to it
     void addFront(T newData){
         node<T>* curr = new node<T>;
         curr->data = newData;
         curr->next = head;
         curr->prev = nullptr;

         if (head != nullptr)
             head->prev = curr;
       
         head = curr;
         
        //when the list is empty
         if (tail == nullptr){
             tail = curr;
         }

         size = size + 1;
     }

     //Add node to the front of the list
     void addBack(T newData){
         node<T>* curr = new node<T>;
         curr->data = newData;
         curr->next = nullptr;
         curr->prev = tail;

         if (tail != nullptr)
             tail->next = curr;

         tail = curr;
         
        //when the list is enpty
         if (head == nullptr){
             head = curr;
         }

         size = size + 1;
     }
     
     // Pop from the back < Don't need to write 0 to prev pointer >
     T pop_back(){
         T result;
         if(size == 0) {
             throw "ERROR: Tried to pop from the back of an empty LinkedList";
         }
         else if (size == 1){
             result = head->data;
             head = nullptr;
             tail = nullptr;
             
         }
         else{
             node<T>* curr = tail;
             tail = tail->prev;
             tail->next = nullptr;
             
             result = curr->data;
             //free the space of the pop node
             delete curr;
         }
         
         size = size - 1;
         
         return result;
     }
     
     // Pop from the front
     T pop_front(){
         T result;
         if(size == 0) {
             throw "ERROR: Tried to pop from the back of an empty LinkedList";
         }
         else if (size == 1){
             result = head->data;
             head = nullptr;
             tail = nullptr;
             
         }
         else{
             node<T>* curr = head;
             head = head->next;
             head->prev = nullptr;
             
             result = curr->data;
             //free the space of the pop node
             delete curr;
         }
         
         size = size - 1;
         
         return result;
     }

     //Length of Linklist
     int length() const{
         return size;
     }


     //Print all data forward
     void printForward(){
         node<T>* curr = head;

         while(curr != nullptr){
             cout << curr->data << ", ";
             curr = curr->next;
         }
         
         cout << endl;
     }

     //Print all data backward
     void printBackward(){
         node<T>* curr = tail;

         while(curr != nullptr){
             cout << curr->data << ", ";
             curr = curr->prev;
         }
         
         cout << endl;
     }
     
     // modify + read the reference of the data at that node
     T& operator[](int i) {
         // i is out of the range
         if(i < 0 || i >= size )
            throw "i is out the range of the list";
         
         node<T> * curr = head;
        
         for(int count = 0; count < i; ++count){
             curr = curr->next;
         }
         
         return curr->data;
     }
};

#endif
