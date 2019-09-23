N, K = map(int, input().split())

def Queries (A, K):
    for i in range(N):
        X = 0
        for j in range(i,N):
            if X+A[j]>K:
                break
            X += A[j]
        
        A[(i+X)%N] = K ^ X
    
    out = 0
    for j in A:
        out += j
    return out



A = map(int, input().split())
arr = list(A)

out_ = Queries(arr, K)
print (out_)