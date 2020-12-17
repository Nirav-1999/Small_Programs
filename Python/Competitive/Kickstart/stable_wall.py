T = int(input())

def get_sequence(wall,available,current_level,seq,letters):
    global flag
    current_letter = set(wall[current_level])
    if letters == []:
        flag = 1
        return seq
    for ele in current_letter:
        get_sequence(wall,available,c)

    if flag == 1:
        return seq
    else:
        return -1

flag = 0

for case in range(T):
    R, C = list(map(int,input().split(" ")))
    wall = []
    letters = set()
    for i in range(R):  
        wall.append(list(input().split(" ")))
        letters.update(wall[i])
    wall.reverse()
    available = [[-1]*C]*R
    available[0] = [0]*C
    seq = get_sequence(wall,available,0,'',list(letters),flag)
        




