T = int(input())

for case in range(T):
    N,D = list(map(int,input().split()))
    bus = list(map(int,input().split()))
    bus.reverse()
    day = D

    for ele in bus:
        if D % ele != 0:
            D = D - D % ele
            day = D
    
    print("Case #{}: {}".format(case+1,day))
