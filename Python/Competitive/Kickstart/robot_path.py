def move(directions,pos_x,pos_y,no_of_times):
    func = {
        'N' : lambda x,y:x-y,
        'S' : lambda x,y:x+y,
        'W' : lambda x,y:x-y,
        'E' : lambda x,y:x+y
    }
    # print("Inside move ",directions)
    # for _ in range(no_of_times):
    if directions == "N" or directions == "S":
        pos_y = func[directions](pos_y,no_of_times)
    else:
        pos_x = func[directions](pos_x,no_of_times)
    return pos_x,pos_y

def find_str(inp_prog,pos_x,pos_y,no_of_times):
    # print(inp_prog)
    count = 0
    
    while(count<len(inp_prog)):
        if inp_prog[count] in num_lst:
            index = count+2
            brack_count = 1
            # print(inp_prog)
            while(brack_count!=0):
                # print("Index = ",index)
                if inp_prog[index]==")":
                    brack_count-=1
                elif inp_prog[index]=="(":
                    brack_count += 1
                index += 1
            # print(int(inp_prog[count]))
            # for _ in range(int(inp_prog[count])):
            pos_x,pos_y = find_str(inp_prog[count+2:index-1],pos_x,pos_y,int(inp_prog[count])*no_of_times)
            # print("(x,y) = ({},{})".format(pos_x,pos_y))

            count = index
        else:
            pos_x,pos_y = move(inp_prog[count],pos_x,pos_y,no_of_times)
            # print("(x,y) = ({},{})".format(pos_x,pos_y))

            count += 1
    return pos_x,pos_y
        


T = int(input())
num_lst = {'2','3','4','5','6','7','8','9'}
end = 1000000000
for case in range(T):

    program = input()
    
    pos_x,pos_y = find_str(program,0,0,1)
    # print(pos_x,pos_y)
    if pos_x < 0 :
        pos_x = (1 + pos_x) % end if pos_x!=-1 else end
    else:
        pos_x = (1 + pos_x) % end if pos_x!=end else 1


    if pos_y < 0 :
        pos_y = (1 + pos_y) % end if pos_y!=-1 else end
    else:
        pos_y = (1 + pos_y) % end if pos_y!=end else 1

    
    # print(pos_x,pos_y)
    print("Case #{}: {} {}".format(case+1,pos_x,pos_y))
