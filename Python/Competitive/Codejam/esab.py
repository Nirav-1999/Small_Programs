import sys

def complement_arr(result,end,B):
    for i in range(1,end+1):
        result[i] = 1 if result[i] == 0 else 0
        result[B-i+1] = 1 if result[B-i+1] == 0 else 0
    return result

def store_result(result,first,last,x1,x2):
    result[first] = x1
    result[last] = x2
    return result

def reverse_arr(result,end,B):
    result[1:] = result[1:][::-1]
    return result

def find_ans(T,B):
    # final_ans = ""
    # for i in range(10):
    #     print(i)
    #     sys.stdout.flush()
    #     value = input()
    #     final_ans = final_ans + str(value)
    # print(final_ans)
    
    result = [-1]*(B+1)
    
    flag_only_sim = 0
    flag_only_diff = 0
    query = 0
    flag = 0
    x = 1
    i = 1
    while i <= B//2:
        print(i)
        query += 1
        sys.stdout.flush()
        x1 = int(input())
        
        # print("x = {}".format(x))
        # print("Query no: {}".format(query))
        
        if query == x:
            # print(query," - ",x)
            x+=10
            flag = 1
        # print("Flag = {}".format(flag))
        
        query += 1
        
        if query == x:
            query -= 1
            continue
        print(B-i+1)
        sys.stdout.flush()
        x2 = int(input())
        # print("Query no: {}".format(query))
        
        

        if(x1 == x2 and flag_only_sim == 0):
            flag_only_sim = 1
            pos_sim = i
        
        elif(x1!=x2 and flag_only_diff == 0):
            flag_only_diff = 1
            pos_diff = i
        if i==1:
            
            result = store_result(result,i,B-i+1,x1,x2)
            flag = 0
            i+=1
            continue
        elif flag==1:
            if((flag_only_sim == 1 and flag_only_diff == 0) or (flag_only_sim == 0 and flag_only_diff== 1) ):
                print(i-1)
                sys.stdout.flush()
                temp1 = int(input())
                query+=1
                if(result[i-1] != temp1 ):
                    result = complement_arr(result,i-1,B)
            else:
                print(pos_sim)
                sys.stdout.flush()
                temp1 = int(input())
                print(pos_diff)
                sys.stdout.flush()
                temp2 = int(input())
                query+=2
                if(temp1 == result[pos_sim] and temp2 != result[pos_diff]):
                    result = reverse_arr(result,i-1,B)
                    
                
                elif(temp1 != result[pos_sim] and temp2 == result[pos_diff]):
                    result = reverse_arr(result,i-1,B)
                    result = complement_arr(result,i-1,B)
                
                elif(temp1 != result[pos_sim] and temp2 != result[pos_diff]):
                    result = complement_arr(result,i-1,B)
            
            result = store_result(result,i,B-i+1,x1,x2)
            flag = 0
        
        else:
            result = store_result(result,i,B-i+1,x1,x2)
        # print(result)
        i+=1
        
    result = [str(x) for x in result][1:]
    ans = ''.join(result)
    print(ans)
    sys.stdout.flush()
                

T,B = list(map(int,input().split(" ")))

for _ in range(T):
    find_ans(T,B)
    res = input()
    if res == 'N':
        break