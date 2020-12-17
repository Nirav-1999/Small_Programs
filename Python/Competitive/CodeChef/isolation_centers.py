T = int(input())

for _ in range(T):
    N,Q = list(map(int,input().split(" ")))
    S = list(input())
    unique = set(S)
    centers = []
    for i in range(Q):
        centers.append(int(input()))
    d = {}
    m = 1
    for ele in S:
        try:
            d[ele] += 1
            if d[ele] > m:
                m = d[ele]
        except KeyError:
            d[ele] = 1
    
    for center in centers:
        x = d.copy()
        count = 0
        # print(x)
        for key in x:
            x[key] -= center

            if x[key] > 0:
                count += x[key]
                # print(key,"-->",count)
        print(count) 
        
