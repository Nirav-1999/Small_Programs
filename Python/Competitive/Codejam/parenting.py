def chk(new_activity,x,y):
    global activities
    if x<=new_activity[0]<y or x<new_activity[1]<=y:
        return 0
    else:
        return 1


def check_interval(new_activity,c):
    for element in c:
        if not chk(new_activity,element[0],element[1]):
            return 0
        
    return 1
            

T = int(input())

for i in range(T):
    c = []
    j = []
    N = int(input())
    activities = []
    order = []
    flag = 0
    for _ in range(N):
        activities.append(list(map(int,input().split(" "))))


    sorted_activities = sorted(activities,key=lambda x: x[0])
    print(sorted_activities)

    for k in range(len(activities)):
        if len(c) == 0:
            c.append(sorted_activities[k])
            continue
        elif(check_interval(sorted_activities[k],c)):
            c.append(sorted_activities[k])
            continue
        if len(j) == 0:
            j.append(sorted_activities[k])
            continue
        elif(check_interval(sorted_activities[k],j)):
            j.append(sorted_activities[k])
            continue
        else:
            flag = 1
            break
    print(c)
    print(j)

    if flag == 1:
        res = "IMPOSSIBLE"
        
    else:
        res = ""
        for ele in activities:
            if ele in c:
                res+="C"
                c.remove(ele)
            else:
                res+="J"
    print("Case #{}: {}".format(i+1,res))
        