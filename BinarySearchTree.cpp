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
    
    // Search if the data is in the tree
};


#endif
