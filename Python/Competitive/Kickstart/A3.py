from heapq import heappop, heappush, heapify 

T = int(input())

for i in range(T):
    heap = []
    heapify(heap)
    N,K = map(int,input().split())
    M = list(map(int, input().split()))
    diff_M = []
    for j in range(N-1):
        diff_M.append(M[j+1]-M[j])
    # print("diif_M--->",diff_M)
    for ele in diff_M:
        heappush(heap,ele*-1)

    while(K>0):
        element = heappop(heap)*-1
        if element==1:
            break
        # print("Top element = {} - K = {}".format(element,K))
        if element%2==0:
            heappush(heap,-1*element//2)
            heappush(heap,-1*element//2)
        else:
            heappush(heap,-1*element//2)
            heappush(heap,-1*((element//2)+1))
        # print(K)
        K -= 1
    # print("Head value of heap : "+str(-1 * heap[0])) 

    # print("The heap elements : ") 
    # for i in heap: 
    #     print(-1 * i, end = ' ') 
    # print("\n") 

    # for j in range(N-1):
    #     diff_M.append(M[j+1]-M[j])
    # print("diff_M -->",diff_M)
    # sorted_M = sorted(diff_M,reverse=True)
    # print("sorted_M -->",sorted_M)
    
    # max_ele = sorted_M[0]
    # index = 0

    # while(K!=0):
    #     if sorted_M[index] >= max_ele:
    #         max_ele = sorted_M[index]
    #         # new_
        

    print("Case #{}: {}".format(i+1,heappop(heap)*-1))
    
            
