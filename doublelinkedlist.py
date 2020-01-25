
'''################################################################################

                            Double Linked List - Truc Tran
                                     Python

###############################################################################'''
# each Node has one value and two pointers( next, previous)
class Node:
    def __init__(self, value=None, next=None, prev= None):
        self.data = value
        self.next = next
        self.prev = prev

# DLL: Double Linked List is a list of nodes.
# Each node in the DDL connects to the previous and the next node in the sequence.
class DLL:
    def __init__(self) :
        self._tail = None
        self._head = None
        self._size = 0

    # pop from the back of the List (tail ->head)
    def pop_back(self):
        if self._size == 0:
            raise ValueError("Cannot pop back. The list is empty")

        curr = self._tail

        if self._size == 1:
            self._tail = None
            self._head = None
        else:
            self._tail = self._tail.prev
            self._tail.next = None

        self._size = self._size - 1

        return curr.data

    # Pop from the front of the list (head-> tail)
    def pop_front(self):
        if self._size == 0:
            raise ValueError("Cannot pop front. The list is empty")

        curr = self._head

        if self._size == 1:
            self._tail = None
            self._head = None
        else:
            self._head = self._head.next
            self._head.prev = None

        self._size = self._size - 1

        return curr.data

    def add_back(self, value):
        print("Add back: ", value)
        curr = Node(value, None, self._tail)
        self._tail.next = curr

        # When the list is NOT EMPTY
        if self._tail != None:
            self._tail.next = curr

        self._tail = curr

        if self._head == None:
            self._head = curr

        self._size = self._size + 1

    def add_front(self, value):
        print("Add Front: ", value)
        curr = Node(value, self._head, None)

        # When the list is NOTempty
        if self._head != None:
            self._head.prev = curr

        self._head = curr

        # When the list is empty
        if self._tail == None:
            self._tail = curr

        self._size = self._size + 1

    # Print all data forward (head->tail)
    def print_forward(self):
        curr = self._head
        print("List in forward order: ", end=" ")
        while curr != None:
            print(curr.data, end = ", ")
            curr = curr.next

        print()

    # Print all data forward (tail->head)
    def print_backward(self):
        curr = self._tail
        print("List in backward order: ", end=" ")
        while curr != None:
            print(curr.data, end = ", ")
            curr = curr.prev

        print()

    def length(self):
        print("size: ", self._size)
