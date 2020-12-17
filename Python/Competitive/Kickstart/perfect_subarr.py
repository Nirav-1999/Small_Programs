import math

T = int(input())

for case in range(T):
    N = int(input())
    A = list(map(int,input().split(" ")))
    sums = []
    for i in range(1,N+1):
        for j in range(i):
            sums.append(sum(A[j:N-i+1+j]))
    count = 0
    # print(sums)

    for ele in sums:
        if ele >= 0: 
            sqrt_ele = math.sqrt(ele)
            if sqrt_ele - math.floor(sqrt_ele) == 0:
                count+=1
    print("Case #{}: {}".format(case+1,count))

