a=input("Enter a string\t")
b=len(a)
x=round(b/2)
for i in range(x):
    if a[0]==a[b-1]:
        z=1
    else:
        z=0
if z==1:
    print("The string is a palindrome")
else:
    print("The string is not a palindrome")
    
        
        
      
