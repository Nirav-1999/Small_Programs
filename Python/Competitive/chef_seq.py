# cook your dish here
def comb(n,r):
        if n==r:
                return 1
        elif r==1:
                return n
        else:
                return comb(n-1,r-1) + comb(n-1,r)
    
for i in range(int(input())):
    A = map(int, input().split())
    A=list(A)
    N = A[0]
    K = A[1]
    A = map(int, input().split())
    arr = list(A)
    arr.sort()
    ele = []
    for j in range(K):
        ele.append(arr[j])
    
    y = set(ele)
#     print(y)
#     print(ele)
#     print("Hey")
#     print(list(y)[-1])
#     print(ele.count(list(y)[-1]))
# #     import pdb; pdb.set_trace()
#     print("Hey")
    no_times = arr.count(list(y)[-1])
    no_excess = ele.count(list(y)[-1])
#     print(no_times)
#     print(no_excess)
    x = comb(no_times,no_excess)
    print(int(x))
