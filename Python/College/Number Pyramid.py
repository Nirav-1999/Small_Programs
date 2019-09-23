a=int(input("Enter a value\t"))
for i in range(a):
    for j in range(a-1-i):
        print(" ",end="")
    for k in range(i+1):
        print(k+1,"",end="")
    for l in range(i):
        print(i-l,"",end="")
    print("\r")
