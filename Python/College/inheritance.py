import datetime

class Employee:
    def __init__(self,fName,lName,salary):
        self.fName = fName
        self.lName = lName
        self.salary = salary

    def fullName(self):
        return self.fName + " " + self.lName

    @classmethod
    def update(cls,str1):
        f,l,s = str1.split(" ")
        return cls(f,l,s)
    
    @staticmethod
    def holiday():
        holiday = datetime.datetime.today().weekday()
        if holiday == 5 or holiday == 6:
            print("Why are you here?!!! Go home!!!")
        else:
            print("Work hard people!!!")

# e = Employee('Nirav','Jain',60000)
# print(e.fullName())
# a = Employee.update("Jack Jill 100000")
# print(a.fullName())
# print(e.salary)
# print(a.salary)
# Employee.holiday()


class Developer(Employee):
    def __init__(self,fName,lName,salary,language):
        super().__init__(fName,lName,salary)
        self.language = language

    def printInfo(self):
        print(super().fullName())
        print("Salary = " + str(self.salary))

# d = Developer("Nirav","Jain",10000,"English")
# d.printInfo()

class Manager(Employee):
    def __init__(self,fName,lName,salary,developer):
        super().__init__(fName,lName,salary)
        if developer == None:
            self.developer = []
        else:
            self.developer = developer
    
    def addDeveloper(self,Developer):
        self.developer.append(Developer)
    
    def remDeveloper(self,Developer):
        if Developer in self.developer:
            self.developer.remove(Developer)
        else:
            print("There are no developers in your company!!")
    
    def printInfo(self):
        print(self.fName,self.lName)
        for d in self.developer:
            d.printInfo()

d1 = Developer("Nirav","Jain",10000,"English")
d2 = Developer("Jack","Jill",50000,"HEnglish")

m = Manager("Tom","Riddle",80000,[d1,d2])
# m.printInfo()
m.addDeveloper(Developer("Harry","Potter",200000,"French"))
# m.printInfo()
m.remDeveloper(d2)
m.printInfo()
