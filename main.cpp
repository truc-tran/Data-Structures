#include <iostream>
using namespace std;
#include "DoublyLinkedList.cpp"
#include "Stack.cpp"
#include "Queue.cpp"

/*---------------------------------MAIN-----------------------------------*/
int main(){
     cout << "Welcome! (^.^) " << endl;
     LinkedList<int> trucList;
     cout << "----------LINKEDLIST--------------" << endl;
     cout << "----------Add to the front:----------" << endl;
     
     for(int i = 1; i < 10; i = i + 1){
         trucList.addFront(i);
     }
     
     trucList.printForward();
     trucList.printBackward();
     cout << "LinkedList length: " << trucList.length() << endl;
     
     cout << "----------Add to the back:----------" << endl;
     for(int i = 2; i < 60; i = i * 3){
         trucList.addBack(i);
     }
     trucList.printForward();
     trucList.printBackward();
     cout << "LinkedList length: " << trucList.length() <<  endl;
     
     cout << "----------Pop back:----------" << endl;
     for( int i = 0; i < 5; ++i)
        trucList.pop_back();
     cout << "LinkedList length: " << trucList.length() << endl;
     
     cout << "----------Modify random element in the list:----------" << endl;
     cout << "trucList[3] = " << trucList[3] << endl;
     trucList[3] = 10000;
     cout << "trucList[3] = " << trucList[3] << endl;
     trucList.printForward();
     
     cout << "\n\n----------STACK:----------" << endl;
     Stack<string> stacklist;
     stacklist.push_top("This");
     stacklist.push_top("is");
     stacklist.push_top("why");
     cout << "Stack length: " << stacklist.size() << endl;
     cout << "Last element in stack is: " << stacklist.pop_top() << endl;
     cout << "Stack length: " << stacklist.size() << endl;
     
     
     cout << "\n\n----------QUEUE:----------" << endl;
     Queue<int> queuelist;
     for( int i = 2; i <300; i = i * 11)
        queuelist.push_bottom(i);
    cout << "Queue length: " << queuelist.size() << endl;
    while(queuelist.size() > 0){
        cout << "First element in Queue is: " << queuelist.pop_top() << endl;
        cout << "Queue length: " << queuelist.size() << endl;
    }
     return 0;
}
