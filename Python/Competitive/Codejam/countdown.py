T = int(input())

def check(A,i,K):
    sub_arr = A[i:i+K]
    # print("sub_arr = ",sub_arr)
    # print("Sorted = ", sorted(sub_arr,reverse=True))
    if sorted(sub_arr,reverse=True) == sub_arr:
        # print("Done")
        return 1
    # index = 0
    # while(index<K):
    #     if sub_arr[index] != K:
    #         return 0 
    #     K -= 1
    #     index += 1
    return 0


for case in range(T):
    N, K = list(map(int,input().split(" ")))
    A = list(map(int,input().split(" ")))

    i = 0
    count = 0
    while i < N - K + 1:
        # print("I = ",i)
        if A[i] == K:
            
            x = check(A,i,K)
            if x==1:
                count+=1
                i += K-1
            # print("Count = ",count)

        i += 1
    print("Case #{}: {} ".format(case+1,count))
