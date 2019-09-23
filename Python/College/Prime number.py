a=int(input("Enter a number\t"))
for i in range(2,a):
    if (a%i==0):
        c=1
        break
    else:
        c=0
if c==1:
    print("It is not a prime number")
else:
    print("It is a prime number")
