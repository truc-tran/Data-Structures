/******************************************************************************

                            Doubly Linked List (by: Truc Tran )

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
class Linklist{
private:
    // Tail, head, size of Linklist
     node<T>* tail;
     node<T>* head;
     int size;

public:
     // Initialize the data in the node--EMPTY
     Linklist(){
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

     //Length of Linklist
     int length(){
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
};

/*---------------------------------MAIN-----------------------------------*/
int main(){
     cout << "Welcome! (^.^) " << endl;
     Linklist<int> trucList;
     cout << "----------Add to the front:----------" << endl;
     
     for(int i = 1; i < 10; i = i + 1){
         trucList.addFront(i);
     }
     
     trucList.printForward();
     trucList.printBackward();
     cout << "Length: " << trucList.length() << endl;
     cout << "----------Add to the back:----------" << endl;
     
     for(int i = 2; i < 60; i = i * 3){
         trucList.addBack(i);
     }

     trucList.printForward();
     trucList.printBackward();
     cout << "Length: " << trucList.length() << endl;
     return 0;
}
