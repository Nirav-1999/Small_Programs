import math
def power_div(x):
    count = 2
    while count<= x:
        if x%count == 0:
            return 1
        count *= 2
    return 0

T = int(input())

for case in range(T):
    flag = 0
    X,Y = list(map(int,input().split(" ")))
    result = []
    pos_x = 0
    pos_y = 0
    if( X % 2 != 0 and Y % 2 != 0):
        flag = 1
    if flag == 0:
        if X%2!=0:
            if power_div(X+1):
                result.append("E")
                pos_x += 1
            else:
                result.append("W")
                pos_x -= 1
            rem = int(math.log(X - pos_x)/math.log(2))
            print("Rem = ",rem)
            i = 1
            while True:
                print(result)
                print(" (pos_x,pos_y) = ({},{}) ".format(pos_x,pos_y))
                print(i)
                if abs(i)==abs(rem):
                    if X > pos_x:
                        result.append("E")
                        pos_x += rem
                    else:
                        result.append("W")
                        pos_x -= rem
                elif pos_y < Y:
                    if pos_y + 2**i <= Y:
                        result.append("N")
                        pos_y = pos_y + 2**i
                    else:
                        flag = 1
                        break
                elif pos_y > Y:
                    if pos_y - 2**i >= Y:
                        result.append("S")
                        pos_y = pos_y - 2**i
                    else:
                        flag = 1
                        break
                
                if(pos_x == X and pos_y==Y):
                    break
                i += 1
                if i == 5:
                    break
        else:
            if power_div(Y+1):
                result.append("N")
                pos_y += 1
            else:
                result.append("S")
                pos_y -= 1
            rem = int(math.log(Y - pos_y)/math.log(2))
            print("Inside Else")
            print("Rem = ",rem)
            i = 1
            while True:
                print(result)
                print(" (pos_x,pos_y) = ({},{}) ".format(pos_x,pos_y))
                print(i)
                if abs(i)==abs(rem):
                    if Y > pos_y:
                        result.append("N")
                        pos_y += rem
                    else:
                        result.append("S")
                        pos_y -= rem
                elif pos_x < X:
                    if pos_x + 2**i <= X:
                        result.append("E")
                        pos_x = pos_x + 2**i
                    else:
                        flag = 1
                        break
                elif pos_x > X:
                    if pos_x - 2**i >= X:
                        result.append("W")
                        pos_x = pos_x - 2**i
                    else:
                        flag = 1
                        break
                
                if(pos_x == X and pos_y==Y):
                    break
                i += 1
                if i == 5:
                    break

    if flag==1:
        result = "IMPOSSIBLE"
    else:
        result = "".join(result)
            
    print("Case #{}: {}".format(case+1,result))