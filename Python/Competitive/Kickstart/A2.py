def adjust(P):
    global beauty_values,weight
    for i in range(len(weight)):
        weight[i] = sum(beauty_values[i][:P])//P

def recalculate_weights():
    global beauty_values,weight
    for i in range(len(weight)):
        if len(beauty_values[i])==0:
            weight[i] = -1
        else:
            max_n = beauty_values[i].index(max(beauty_values[i]))
            weight[i] = sum(beauty_values[i][:max_n+1])//(max_n+1)


T = int(input())
for e in range(T):
    N,K,P = map(int,input().split())
    beauty_values = []
    weight = []
    for i in range(N):
        new_k = list(map(int, input().split()))

        y = new_k.index(max(new_k))
        sum_new_k = sum(new_k[:y+1])
        # print("(sum_new_k,y+1) ==> ({},{})".format(sum_new_k,y+1))
        weight.append(sum_new_k//(y+1))
        beauty_values.append(new_k)

    total = 0
    while P != 0:
        # print("===========")
        # print(beauty_values)
        # print(weight)
        # print("===========")
        x = max(weight)
        y = weight.index(x)
        z = beauty_values[y].index(max(beauty_values[y]))
        # print("(x,y,z) => ({},{},{})".format(x,y,z))

        if z+1 <= P:
            total += sum(beauty_values[y][:z+1])
            beauty_values[y] = beauty_values[y][z+1:]
            recalculate_weights()
            
        else:
            adjust(P)
            x = max(weight)
            y = weight.index(x)
            total += sum(beauty_values[y][:P])
            # print(total)
            break
        # print(total)
        # print("============")
        P = P - z - 1
    print("Case #{}: {}".format(e+1,total))
