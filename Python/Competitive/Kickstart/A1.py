T = int(input())

for i in range(T):
    N,B = map(int,input().split())
    A = list(map(int, input().split()))
    
    A.sort()
    count = 0
    total = 0
    for ele in A:
        if total+ele<=B:
            total += ele
            count+=1
        else:
            break
    print("Case #{}: {}".format(i+1,count))
