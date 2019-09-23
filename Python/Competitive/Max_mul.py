def solve (A,N):
    arr = list(A)
    arr.sort(reverse = True)
    return max(arr[0]*arr[1],arr[N-1]*arr[N-2])

    
T = int(input())

for _ in range(T):
    N = int(input())
    A = map(int, input().split())
    out_ = solve(A,N)
    print (out_)