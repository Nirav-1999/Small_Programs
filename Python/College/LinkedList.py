class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def create(self):
        n = int(input("Enter no. of nodes"))
        for i in range(n):
            d = int(input("Value = "))
            x = Node(d)
            if self.head is None:
                self.head = x
            else:
                temp = self.head
                while(temp.next is not None):
                    temp = temp.next
                temp.next = x

    def append(self,data):
        x = Node(data)
        if(self.head is None):
            self.head = x
        else:
            temp = self.head
            while(temp.next is not None):
                temp = temp.next
            temp.next = x

    def begin(self,data):
        x = Node(data)
        if(self.head is None):
            self.head = x
        else:
            x.next = self.head
            self.head = x

    def between(self,data,after):
        x = Node(data)
        temp = self.head
        while(temp.data != after):
            prev = temp
            temp = temp.next
        prev.next = x
        x.next = temp
    
    def delete(self,data):
        if(self.head is None):
            print("List is empty")
        else:
            temp = self.head
            while(temp.data != data and temp != None):
                prev = temp
                temp = temp.next
            
            if temp is None:
                print("Value not found")

            elif temp is self.head:
                self.head = temp.next
                del(temp)
            elif temp.next is None:
                prev.next = None
                del(temp)
            else:
                prev.next = temp.next
                del(temp)
    
    def display(self):
        if(self.head is None):
            print("List is empty")
        else:
            temp = self.head
            while(temp is not None):
                print(temp.data)
                temp = temp.next

ll = LinkedList()
ll.create()
ll.display()
ll.append(23)
ll.display()
ll.begin(12)
ll.display()
ll.between(72,44)
ll.display()
ll.delete(44)
ll.display()