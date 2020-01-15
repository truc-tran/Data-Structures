#include <iostream>
using namespace std;
#include "DoublyLinkedList.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "BinarySearchTree.cpp"
#include "HashMap.cpp"

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
    int num = 0;
    cout << "\nFinding " << num << ": "<< (tree.find(num) ? "true" : "false") << endl;
    cout << "\nFinding " << num << ": "<< (tree.iterativeFind(num) ? "true" : "false") << endl;
    cout << "TRAVERSAL: " << endl;
    tree.print(TRAVERSE_PRE_ORDER);
    tree.print(TRAVERSE_IN_ORDER);
    tree.print(TRAVERSE_POST_ORDER);
}

// return positive integer for any string keyword
unsigned int hashString (string word) {
    unsigned int result = 0x12345678;

    for (int i = 0; i < word.size(); ++i) {
        // XOR the result with each letter: make sure it is random
        result = result ^ word[i];
        // removes commutative property & modifies all bits in the int: rotate left
        result = _rotl(result, 5);
    }

    return result;
}

void printHashMap () {
    HashMap<string> hm(hashString);

    hm.insert("Facebook", "Stock Price($): -256.89");
    hm.insert("Tesla", "Stock Price($): $0.99 -> cents");
    cout << "Tesla: " <<  hm.at("Tesla") << endl;
    hm.insert("Tesla", "Stock Price($): priceless");
    cout << "Tesla: " << hm.at("Tesla") << endl;
    cout << "Size of hash map: " << hm.getSize() << endl;
}

int main(){
    printLinkedList();
    printStack();
    printQueue();
    printBinaryTree();
    printHashMap();

    return 0;
}
