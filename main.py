from doublelinkedlist import DLL

def printDoubleLinkedList():
    dl = DLL()
    print("----------Double Link List (Python version):----------")
    #print("pop_back: ", dl.pop_back())
    print("----------Add to the front:----------")
    dl.add_front(2)
    dl.add_front("whfeif")
    dl.add_front(123)
    dl.print_forward()
    dl.print_backward()
    dl.length()
    print("----------Add to the back:----------")
    dl.add_back(1)
    dl.add_back(0)
    dl.add_back(-1)
    dl.print_forward()
    dl.print_backward()
    dl.length()
    print("----------Pop back:----------")
    for i in range(2):
        print("pop_back: ", dl.pop_back())
    dl.length()
    print("----------Pop front:----------")
    for i in range(2):
        print("pop_front: ", dl.pop_front())
    dl.length()

def main():
    printDoubleLinkedList()

if __name__ == '__main__':
    main()
