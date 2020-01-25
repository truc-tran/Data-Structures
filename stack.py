'''################################################################################

                            Stack - Truc Tran
                                Python
                            (FILO ~ LIFO)
###############################################################################'''

# StackNode is the node used to build stack, only has prev pointer
class StackNode:
    def __init__(self, value=None, prev= None):
        self.data = value
        self.prev = prev

# Stack is a data structure with nodes as its component (First In Last Out)
class Stack:
    def __init__(self):
        self._top = None
        self._size = 0


    def push(self, value):
        # Create new node with data in it
        self._top  = StackNode(value, self._top)
        self._size = self._size + 1

    def pop(self):
        if self._size == 0:
            print("Stack has nothing to pop")
            return

        curr = self._top
        self._top = self._top.prev
        self._size = self._size - 1

        return curr.data

    def print(self):
        print("Stack (top->bottom): ", end=" ")
        curr = self._top

        while curr:
            print(curr.data, end=", ")
            curr = curr.prev

        print()

    def get_size(self):
        return self._size
