
def get_ans_two(x):
    if (x[0] == "R" and x[1] == "P") or (x[0] == "P" and x[1] == "R"):
        return 'P'
    elif (x[0] == "R" and x[1] == "S") or (x[0] == "S" and x[1] == "R"):
        return 'R'
    else:
        return 'S'

def get_ans_one(x):
    if x == 'R':
        # print("Inside R we get P")
        return 'P'
    elif x == 'P':
        # print("Inside P we get S")
        return 'S'
    else:
        # print("Inside S we get R")
        return 'R'

T = int(input())

for case in range(T):
    
    A = int(input())
    flag = 0
    program = []
    solution = []
    max = 0
    for i in range(A):
        program.append(input())

    
    index = 0
    
    while program:
        # print("Program = ",program)
        # print("Solution = ",solution)
        x = set()

        for ele in program:
            if ele[index % len(ele)] not in x:
                x.add(ele[index % len(ele)])

        # print("x = ",x)

        if len(x) == 3:
            flag = 1
            break
        elif len(x) == 2:
            solution.append(get_ans_two(list(x)))
            temp = []
            for ele in program:
                if ele[index % len(ele)] == solution[-1]:
                    temp.append(ele)
            program = temp
        else:
            # print("x = ",list(x)[0])
            # print("returned = ",get_ans_one(list([x][0])))
            solution.append(get_ans_one(list(x)[0]))
            # print("Solution for 1 = ",solution)
            program = []
        index += 1
    
    if flag:
        y = "IMPOSSIBLE"
    else:
        y = ''.join(solution)

    print("Case #{}: {}".format(case+1,y))
            


