#ifndef BINARYSEARCHTREE_CPP
#define BINARYSEARCHTREE_CPP
/******************************************************************************

                            Binary Search Tree (by: Truc Tran)
                            - Depth First Traversals:
                            Insert order: 8 4 3 6 9 1 2 5
                            (a) Inorder (Left, Root, Right) : 1 2 3 4 5 6 7 8 9
                            (b) Preorder (Root, Left, Right) : 8 4 3 1 2 5 6 9
                            (c) Postorder (Left, Right, Root) : 2 1 3 5 6 4 9 8

*******************************************************************************/
#include <iostream>
using namespace std;
#include "Stack.cpp"

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value, Node* l, Node* r) {
            data = value;
            left = l;
            right = r;
        }
    };

    Node* root;
    int numElems;

public:
    BinarySearchTree() {
        root = nullptr;
        numElems = 0;
    }

    // Size of the tree (total number of node)
    int size(){
        return numElems;
    }

    // Insert Node on the binary tree (no return)
    void insert(T newData) {
        ++numElems;

        // Tree is empty
        if (root == nullptr) {
            root = new Node(newData, nullptr, nullptr);
            return;
        }

        // The rest of the cases
        Node* curr = root;
        Node* next = curr;
        bool left;

        while (next != nullptr) {
            curr = next;

            if (newData < curr->data) {
                next = curr->left;
                left = true;
            } else {
                next = curr->right;
                left = false;
            }
        }

        if (left) {
            curr->left = new Node(newData, nullptr, nullptr);
        } else {
            curr->right = new Node(newData, nullptr, nullptr);
        }
    }


    // (a) Print InOrder function (Left, Root, Right): 1 2 3 4 5 6 7 8 9
    void printInOrder(){
        cout << "InOrder: ";
        if (root == nullptr)
            cout << "There is nothing in the tree ^.^" << endl;

        // start from the root
        dfsInOrder(root);
        cout << endl;
    }

    // print all values from the node to its decestors:
    void dfsInOrder(Node* ptr){
        if (ptr == nullptr) {
            return;
        }

        // Visit left, print curr node, right
        dfsInOrder(ptr->left);
        cout << ptr->data << ", ";
        dfsInOrder(ptr->right);
    }

    // (b) Print Preorder function (Root, Left, Right): 8 4 3 1 2 5 6 9
    void printPreOrder(){
        cout << "PreOrder: ";
        if (root == nullptr)
            cout << "There is nothing in the tree ^.^" << endl;

        // start from the root
        dfsPreOrder(root);
        cout << endl;
    }

    // print all values from the node to its decestors:  Root, L , R
    void dfsPreOrder(Node* ptr){

        if (ptr == nullptr) {
            return;
        }

        //print the current node value
        cout << ptr->data << ", ";

        // Visit left and right
        dfsPreOrder(ptr->left);
        dfsPreOrder(ptr->right);
    }

    // (c) Print PostOrder function (Left, Right, Root): 2 1 3 5 6 4 9 8
    void printPostOrder(){
        cout << "PostOrder: ";
        if (root == nullptr)
            cout << "There is nothing in the tree ^.^" << endl;

        // start from the root
        dfsPostOrder(root);
        cout << endl;
    }

    // print all values from the node to its decestors: L, R, Root
    void dfsPostOrder(Node* ptr){
        if (ptr == nullptr) {
            return;
        }

        // Visit left and right
        dfsPostOrder(ptr->left);
        dfsPostOrder(ptr->right);
        cout << ptr->data << ", ";
    }
    
    /*------------------------------------NOT FUNCTIONING (not tail-recursive)----------------------------------------------------------*/
    // Print the tree in the order you choose: 0-PreOrder, 1-InOrder, 2-PostOrder
    #define TRAVERSE_PRE_ORDER 0
    #define TRAVERSE_IN_ORDER 1
    #define TRAVERSE_POST_ORDER 2
    void print (int order) {
        if (root == nullptr) {
            cout << "There is nothing in the tree ^.^" << endl;
            return;
        }
        
        Stack<Node*> myStack;
        myStack.push_top(root);
        
        while (myStack.size() != 0) {
            Node* curr = myStack.pop_top();
            
            if (curr == nullptr)
                continue;
            
            if (order ==  TRAVERSE_PRE_ORDER) {
                // Preorder (Root, Left, Right): 8 4 3 1 2 5 6 9
                cout << curr->data << ", ";
                myStack.push_top(curr->left);
                myStack.push_top(curr->right);
            } else if (order == TRAVERSE_IN_ORDER) {
                // InOrder (Left, Root, Right): 1 2 3 4 5 6 7 8 9
                myStack.push_top(curr->left);
                cout << curr->data << ", ";
                myStack.push_top(curr->right);
            } else if (order == TRAVERSE_POST_ORDER) {
                // PostOrder (Left, Right, Root): 2 1 3 5 6 4 9 8
                myStack.push_top(curr->left);
                myStack.push_top(curr->right);
                cout << curr->data << ", ";
            }
            
        }
        
        cout << "\n\n";
        
    }
    /*------------------------------------NOT FUNCTIONING (not tail-recursive)----------------------------------------------------------*/
    
    

    // Search if the data is in the tree with RECURSION
    bool find(T elem) {
        return dfsFind(root, elem);
    }

    bool dfsFind(Node* curr, T elem) {
        if (curr == nullptr)
            return false;

        // Look at the current node and compare in order to go left or right
        if( curr->data == elem) {
            return true;
        } else if (curr->data > elem) {
            return dfsFind(curr->left, elem);
        } else {
            return dfsFind(curr->right, elem);
        }
    }

    // Search WITHOUT RECURSION
    bool iterativeFind(T elem) {
        Stack<Node*> myStack;
        myStack.push_top(root);

        // Added the node everytime we visit until nothing
        while (myStack.size() != 0) {
            Node* curr = myStack.pop_top();

            if (!curr) {
                break;
            }

            if (elem == curr->data) {
                return true;
            } else if (elem < curr->data) {
                myStack.push_top(curr->left);
            } else {
                myStack.push_top(curr->right);
            }

        }

        return false;
    }
};


#endif
