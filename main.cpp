#include <iostream>
using namespace std;
#include "DoublyLinkedList.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "BinarySearchTree.cpp"

/*---------------------------------MAIN-----------------------------------*/
void printLinkedList(){
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
}

void printStack(){
    cout << "\n\n----------STACK:----------" << endl;
    Stack<string> stacklist;
    stacklist.push_top("This");
    stacklist.push_top("is");
    stacklist.push_top("why");
    cout << "Stack length: " << stacklist.size() << endl;
    cout << "Last element in stack is: " << stacklist.pop_top() << endl;
    cout << "Stack length: " << stacklist.size() << endl;
}

void printQueue(){
    cout << "\n\n----------QUEUE:----------" << endl;
    Queue<int> queuelist;
    for( int i = 2; i <300; i = i * 11)
        queuelist.push_bottom(i);
    cout << "Queue length: " << queuelist.size() << endl;
    while(queuelist.size() > 0){
        cout << "First element in Queue is: " << queuelist.pop_top() << endl;
        cout << "Queue length: " << queuelist.size() << endl;
    }
}

void printBinaryTree(){
    cout << "\n\n----------BINARY TREE:----------" << endl;
    Queue<int> queuelist;
    BinarySearchTree<int> tree;
    cout << "Size of Binary Tree: " << tree.size() << endl;

    tree.insert(8);
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);
    tree.insert(9);
    tree.insert(1);
    tree.insert(2);
    tree.insert(5);

    cout << "Size of Binary Tree: " << tree.size() << endl;

    // PRINT Orders
    tree.printPreOrder();
    tree.printInOrder();
    tree.printPostOrder();

    // Find Node
    int num = 9;
    cout << "\nFinding " << num << ": "<< (tree.find(num) ? "true" : "false") << endl;
}

int main(){
    printLinkedList();
    printStack();
    printQueue();
    printBinaryTree();
    return 0;
}
