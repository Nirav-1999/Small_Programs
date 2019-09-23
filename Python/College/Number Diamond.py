a=int(input("Enter a value\t"))
for i in range(a):
    for j in range(a-1-i):
        print(" ",end="")
    for k in range(i+1):
            print(i+1,"",end="")
    print("\r")
for i in range(a):
    for j in range(i+1):
        print(" ",end="")
    for k in range(a-1-i):
            print(a-i-1,"",end="")
    print("\r")
