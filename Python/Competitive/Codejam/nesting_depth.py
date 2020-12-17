T = int(input())

for i in range(T):
    s = input()
    num_s = [int(x) for x in s]
    # print(num_s)
    count = 0
    index = 0
    paran = {}
    for k in range(len(s)):
        paran[str(k)] = []
    
    while(True):

        while(num_s[index] != 0):
            
            paran[str(index)].append('(')
            j = index
            while j<len(s):
                if num_s[j] == 0:
                    break
                num_s[j] -= 1  
                j+=1 
            # print(j)   
            paran[str(j-1)].append(')')
            # print(paran)
            
        index += 1          
        if (len(set(num_s)) == 1 and (0 in set(num_s)) or index == len(s)):
            break
    new_str = ""
    for k in range(len(s)):
        new_str += '(' * paran[str(k)].count('(')
        new_str += s[k]
        new_str += ')' * paran[str(k)].count(')')
    print("Case #{}: {}".format(i+1,new_str))