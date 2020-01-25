from doublelinkedlist import DLL
from stack import Stack
from queue import Queue


def print_queue():
    print("\n---------------------Queue---------------------\n")
    q = Queue()
    q.push("Hello")
    q.push("World")
    q.push("From")
    q.push("Truc")
    q.push("2020")
    q.print()
    print("size: ", q.get_size())

    q.pop()
    q.pop()
    q.print()
    print("size: ", q.get_size())

def print_stack():
    print("\n---------------------Stack---------------------\n")
    s = Stack()
    s.push("2020")
    s.push("Truc")
    s.push("from")
    s.push("World")
    s.push("Hello")
    s.print()
    print("size: ", s.get_size())

    s.pop()
    s.pop()
    s.print()
    print("size: ", s.get_size())

def print_doubleLinkedList():
    print("\n---------------------Double Linked List---------------------\n")
    dl = DLL()
    #print("pop_back: ", dl.pop_back())
    print()
    dl.add_front(2)
    dl.add_front("whfeif")
    dl.add_front(123)
    dl.print_forward()
    dl.print_backward()
    dl.length()

    print()
    dl.add_back(1)
    dl.add_back(0)
    dl.add_back(-1)
    dl.print_forward()
    dl.print_backward()
    dl.length()

    print()
    for i in range(2):
        print("pop_back: ", dl.pop_back())
    dl.length()

    print()
    for i in range(2):
        print("pop_front: ", dl.pop_front())
    dl.length()

def main():
    print_doubleLinkedList()
    print_stack()
    print_queue()

if __name__ == '__main__':
    main()
