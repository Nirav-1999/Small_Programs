T = int(input())

for case in range(T):

    N = int(input())
    days = list(map(int,input().split()))
    days = [0] + days + [0]
    max_num = 0
    count = 0
    for i in range(1,len(days)-1):
        if i==1:
            if days[i] > days[i+1]:
                count += 1
                
        elif i == len(days) - 2:

            if days[i] > max_num:
                count += 1
        else:
            if (days[i] > days[i+1] and days[i] > max_num):
                count += 1
                
        if days[i] > max_num:
            max_num = days[i]
            


        
    
    print("Case #{}: {}".format(case+1,count))
