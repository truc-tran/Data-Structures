#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP
/******************************************************************************

                            Binary Tree (by: Truc Tran)

*******************************************************************************/
#include <iostream>
using namespace std;

template <typename T>
class BinaryTree {
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
        
public:
    BinaryTree() {
        root = nullptr;
    }
    
    // Insert Node on the binary tree (no return)
    void insert(T newData) {
        // Tree is empty
        if (root = nullptr) {
            root = new Node(newData, nullptr, nullptr);
            return;
        }
        
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
    
    // Search if the data is in the tree
};


#endif
