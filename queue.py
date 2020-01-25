'''################################################################################

                            QUEUE - Truc Tran
                                Python
                            (FIFO ~ LILO)
###############################################################################'''

# QueueNode is the node used to build stack, only has next pointer
class QueueNode:
    def __init__(self, value=None, next= None, prev=None):
        self.data = value
        self.next = next
        self.prev = prev

# Queue is a data structure with nodes as its component (First In First Out)
class Queue:
    def __init__(self):
        self._head = None
        self._tail = None
        self._size = 0



    def push(self, value):
        curr = QueueNode(value, self._tail, None)

        if (self._tail != None):
            self._tail.prev = curr

        self._tail = curr

        if self._head == None:
            self._head = self._tail

        self._size = self._size + 1

    def pop(self):

        if self._size == 0:
            print("Stack has nothing to pop")
            return
        elif self._size == 1:
            curr = self._head
            self._head = None
            self._tail = None
        else:
            curr = self._head
            self._head = self._head.prev
            self._head.next = None

        self._size = self._size - 1

        return curr.data

    def print(self):
        print("Queue (first->last): ", end=" ")
        curr = self._head

        while curr:
            print(curr.data, end=", ")
            curr = curr.prev

        print()

    def get_size(self):
        return self._size
