def solve (arr, Q, K, R, L):
    out = -1
    while(L<=R and arr[L-1]%K==0):
        out = L
        L += 1
    return out
        
    

N = int(input())
A = map(int, input().split())
arr = list(A)
Q = int(input())
for i in range(0,Q):
    Z = map(int, input().split())
    X = list(Z)
    L = X[0]
    R = X[1]
    K = X[2]

    out_ = solve(arr, Q, K, R, L)
    print (out_)