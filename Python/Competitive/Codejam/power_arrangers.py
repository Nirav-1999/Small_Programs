import sys
import math

def get_final(dict_ans,key,sol,pos):
    
    tmp = ['A','B','C','D','E']

    dict_nxt = {
        'A': [],
        'B': [],
        'C': [],
        'D': [],
        'E': [],
    }
    # print(dict_ans)
    
    for i in dict_ans[key]:
        print(str(i+1))
        sys.stdout.flush()
        res = input()
        if pos == 2:
            temp = sol + res
            for ele in tmp:
                if ele not in temp:
                    not_there = ele
            sol += not_there + res
            # print("Final Sol = ",sol)

            return sol

        dict_nxt[res].append(i+1)
    
    # print("Next")
    # print(dict_nxt)

    for key in dict_ans:
        if len(dict_nxt[key]) != math.factorial(pos-1) and len(dict_nxt[key]) != 0:
            sol += key
            # print("Sol = ",sol)

            sol = get_final(dict_nxt,key,sol,pos-1)
            return sol



def find_ans(F,pos):
    
    sol = ''

    dict_ans = {
        'A': [],
        'B': [],
        'C': [],
        'D': [],
        'E': [],
    }

    for i in range(1,595,5):
        print(str(i))
        sys.stdout.flush()
        res = input()
        dict_ans[res].append(i)

    for key in dict_ans:
        if len(dict_ans[key]) != math.factorial(pos-1):
            sol += key
            # print("Sol = ",sol)
            sol = get_final(dict_ans,key,sol,pos-1)
    
    print(sol)
    sys.stdout.flush()
    res = input()
    if res == "Y":
        return 1
    else:
        return 0
            
            
        
T,F = list(map(int,input().split(" ")))

for _ in range(T):
    a = find_ans(F,5)
    if a == 0:
        break 
