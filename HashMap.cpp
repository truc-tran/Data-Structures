#ifndef HASHMAP_CPP
#define HASHMAP_CPP
/******************************************************************************

                            HASH MAP (by: Truc Tran)

*******************************************************************************/
#include <iostream>
using namespace std;

template <typename T>
class HashMap {
private:
    struct Node {
        T key;
        T value;
        bool filled;

        Node() {
            filled = false;
        }

        Node (T k, T v, bool o) {
            key = k;
            value = v;
            filled = o;
        }
    };

    Node* arr;
    int capacity;
    int size;
    unsigned int (*hashFunc)(T);

public:
    HashMap () {
        throw "HashMap needs to have hash function";
    }

    HashMap (unsigned int (*hf)(T)) {
        capacity = 50;
        arr = new Node[capacity];
        size = 0;
        hashFunc = hf;
    }

    HashMap (unsigned int (*hf)(T), int cap) {
        capacity = cap;
        arr = new Node[capacity];
        size = 0;
        hashFunc = hf;
    }

    // Insert an element into the HashMap array with hashed key
    void insert (T key, T value) {
        unsigned int i = hashFunc(key) % capacity;

        if (!arr[i].filled) {
            ++size;
        }

        arr[i] = Node(key, value, true);
    }

    T at (T key) {
        int i = hashFunc(key) % capacity;
        return arr[i].value;
    }

    int getCapacity () {
        return capacity;
    }

    int getSize () {
        return size;
    }
} ;

#endif
