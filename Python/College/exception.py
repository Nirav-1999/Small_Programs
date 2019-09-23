
class MyException(Exception):
    def __init__(self,value):
        self.value = value
    
    def __str__(self):
        return "Don't add anything like " + repr(self.value)
try:
    raise(MyException(2))
except MyException as e:
    print(e)

def div(x,y):
    return x/y

try:
    print(div(4,2))
    raise(ValueError)
    print(div(4,0))
except (ZeroDivisionError,ValueError):
    print("Denominator can't be zero")
finally:
    print("I will be exected nonetheless")

