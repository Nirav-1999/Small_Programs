
T = int(input())

for case in range(T):
    sol = []
    final = ['']*10
    some_dict = {
        '0':set(),
        '1':set(),
        '2':set(),
        '3':set(),
        '4':set(),
        '5':set(),
        '6':set(),
        '7':set(),
        '8':set(),
        '9':set()
        
    }
    letters = set()
    U = int(input())
    for i in range(10000):
    
        q,r = input().split(" ")
        q = int(q)
        for l in r:
            letters.add(l)
        if 9 >= q >=0:
            sol.append([q,r])
    # print(sol)
    for ele in sol:
        some_dict[str(ele[0])].add(tuple(ele))
    # print(some_dict)
    # print(letters)
    for i in range(10):
        if some_dict[str(i)] != set() and len(some_dict[str(i)]) == 1:
            final[i] = list(some_dict[str(i)])[0][1]
            letters.remove(final[i])
        elif some_dict[str(i)] == set():
            continue
        else:
            temp = []
            for ele in some_dict[str(i)]:
                if list(ele)[1] not in letters:
                    temp.append(ele)
            # print("Temp " + str(temp))
            for ele in temp:
                some_dict[str(i)].remove(ele)
            
            if len(some_dict[str(i)]) == 1:
                final[i] = list(some_dict[str(i)])[0][1]
                letters.remove(final[i])

            else:
                max_ct = 0
                ind = 0
                for ele in some_dict[str(i)]:
                    a = sol.count(list(ele))
                    if a > max_ct:
                        max_ct  = a
                        ind = ele
                final[i] = list(ele)[1]
                letters.remove(final[i])

        # print("++++++++++++++ ",final)
        # print("letters = ",letters)

    letters = list(letters)
    if letters:
        index = 0
        for ele in range(len(final)):
            if final[ele] == "":
                final[ele] = letters[index]
                index += 1
    # print(final)

    # for key in some_dict:
    #     if key == '0':
    #         if some_dict[key]:
    #             final[int(key)] = some_dict[key][0][1]
    print("Case #{}: {}".format(case+1,"".join(final)))
            


