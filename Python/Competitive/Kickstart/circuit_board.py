T = int(input())

def find_max(arr,R,max_len):
    size = max(R,max_len)
    for i in range(R-1):
        len1 = len(arr[i])
        temp_inter = arr[i].copy()
        for j in range(i+1,R):
            new_inter = []
            len2 = len(arr[j])
            k = 0
            ct = 0

            while k < len2 and ct < len1:
                x = arr[j][k].intersection(temp_inter[ct])
                if bool(x) == False:
                    if k == len2-1:
                        ct += 1
                    else:
                        k += 1
                    continue
                size = max(size,len(x)*(j+1))
                new_inter.append(x)
                if ct == len1 - 1:
                    k+=1 
                else:
                    ct += 1
                
            temp_inter = new_inter.copy()
    return size



def find_subarrays(arr,K):
    
    intervals = [{0}]
    ct = 0
    min_ele = max_ele = arr[0]
    max_inter_len = 0
    for i in range(1,len(arr)):
        
        min_ele = min(min_ele,arr[i])
        max_ele = max(max_ele,arr[i])

        if max_ele - min_ele <= K:
            intervals[ct].add(i)
        else:
            intervals.append({i})
            min_ele = max_ele = arr[i]
            ct+=1
        max_inter_len = max(max_inter_len,len(intervals[ct]))
    return intervals,max_inter_len


for case in range(T):

    R,C,K = list(map(int,input().split()))
    
    board = []
    count = 0
    intervals = []
    max_len_row = 0

    for i in range(R):
        board.append(list(map(int,input().split())))

    for row in board:
        sub_arr,max_inter_len = find_subarrays(row,K)
        intervals += [sub_arr]
        max_len_row = max(max_len_row,max_inter_len)

    count = find_max(intervals,R,max_len_row)
    
    # print(intervals)
    print("Case #{}: {}".format(case+1,count))
