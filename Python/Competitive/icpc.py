t = int(input())

for i in range(t):
    flag = 0
    inp = str(int(input()))
    a = list(map(int,list(inp)))
    if a[0]>a[1]:
        a.remove(a[0])
    elif(a[0]==a[1]):
        for i in range(1,len(a)-1):
            if(a[i]>a[i+1]):
                a.remove(a[i])
                flag=1
                break
            elif(a[i] < a[i+1]):
                x = a.index(max(a))
                a.remove(a[x])
                flag=1
                break
        
        if(flag==0):
            a.remove(a[0])    
    elif 0 in a:
        x = a.index(0)
        left_max = max(a[:x])
        a.remove(left_max)

    else:
        x = a.index(max(a))
        a.remove(a[x])
    a = list(map(str,a))
    a = ''.join(a)
    a = int(a)
    print(a)
