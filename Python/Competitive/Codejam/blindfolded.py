import sys

def find_intersection(x,y,end,pt):
    # dr_dict = {
    #     'dec' : lambda x: -x,
    #     'inc' : lambda x: x,
        
    # }
    # print("x : {}\ty : {}\tend : {}\tpt : {}".format(x,y,end,pt))
    if pt == 'x':
        print(str((x + end)//2) + " " + str(y)) 
    else:
        print(str(x) + " " + str((y + end)//2))

    sys.stdout.flush()
    res = input()
    if res == "CENTER":
        return "Done"
    elif res == "MISS":
        if pt == "x":
            if abs(x - end) == 1:
                return x
            return find_intersection(x,y,(x + end)//2,'x')
        else:
            if abs(y - end) == 1:
                return y
            return find_intersection(x,y,(y + end)//2,'y')
    else:
        if pt == 'x':
            if abs(x - end) == 1:
                return x
            return find_intersection((x + end)//2,y,end,'x')
        else:
            if abs(y - end) == 1:
                return y
            return find_intersection(x,(y + end)//2,end,'y')

def find_final(x,y):
    i = 1
    sign = -1
    while True:
        for _ in range(i):
            x += sign
            print(str(x) + " " + str(y))
            sys.stdout.flush()
            res = input()
            if res=="CENTER":
                return 1
        for _ in range(i):
            y += sign
            print(str(x) + " " + str(y))
            sys.stdout.flush()
            res = input()
            if res=="CENTER":
                return 1
        sign *= -1
        i += 1


def find_ans(T,A,B):
    a = 10**9
    initial_cases = [(0,0),(a//2,0),(-a//2,0),(0,a//2),(0,-a//2),(a//2,a//2),(a//2,-a//2),(-a//2,-a//2),(-a//2,a//2)]
    for query in initial_cases:
        print(str(query[0]) + " " + str(query[1]))
        sys.stdout.flush()
        res = input()
        if res == 'CENTER':
            return 1
        elif res == "HIT":
            # start_pt = [query[0],query[1]]
            left = find_intersection(query[0],query[1],-a,'x')
            if left == "Done":
                return 1
            right = find_intersection(query[0],query[1],a,'x')
            if right == "Done":
                return 1
            top = find_intersection(query[0],query[1],a,'y')
            if top == "Done":
                return 1
            bottom = find_intersection(query[0],query[1],-a,'y')
            if bottom == "Done":
                return 1
            # print("left = {}\tright = {}\ttop = {}\tbottom = {}".format(left,right,top,bottom))

            # nxt_step(start_pt,A,B)
            x_center = (left + right)//2
            y_center = (top + bottom)//2
            print(str(x_center) + " " + str(y_center))
            sys.stdout.flush()
            res = input()
            if(res == "CENTER"):
                return 1
            else:
                a = find_final(x_center,y_center)
                if a == 1:
                    return 1
        
        
        
T,A,B = list(map(int,input().split(" ")))

for _ in range(T):
    a = find_ans(T,A,B)
    if a == 0:
        break 
