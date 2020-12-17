T = int(input())
def create_row(pascal_triangle,r):
    if r == len(pascal_triangle)-1:
        pascal_triangle.append([])
        for i in range(r+2):
            if i==0 or i==len(pascal_triangle)-1:
                pascal_triangle[-1].append(1)
            else:
                pascal_triangle[-1].append(pascal_triangle[r][i-1] + pascal_triangle[r][i])
    return pascal_triangle
        

for case in range(T):
    N = int(input())
    res_lst = [[1,1]]
    pascal_triangle = [[1],[1,1]]
    count = 1
    r = 0
    k = 0
    while(count != N):
        cond = {
            '0' : [r + 1, k + 1],
            '1' : [r + 1, k],
            '2' : [r, k - 1],
            '3' : [r, k + 1],
            '4' : [r - 1, k],
            '5' : [r - 1, k - 1],
        }
        if r == 0 and k == 0:
            r = 1
            k = 0
            res_lst.append([r+1,k+1])
            count += 1
            continue
        pascal_triangle = create_row(pascal_triangle,r)
        print("Pascal triangle")
        print(pascal_triangle)
        for i in range(6):
            some = cond[(str(i))]
            # print("some[0] = {} and some[1] = {}".format(some[0],some[1]))
            try:
                if some[1]>=0 and some[1]<=r+1:
                    if count + pascal_triangle[some[0]][some[1]] <= N and [some[0]+1,some[1]+1] not in res_lst:
                        count += pascal_triangle[some[0]][some[1]]
                        r = some[0]
                        k = some[1]
                        res_lst.append([r+1,k+1])
            except IndexError:
                pass


    print(res_lst)
    print("Case #{}: ".format(case+1))

# (ri - 1, ki - 1), (ri - 1, ki), (ri, ki - 1), (ri, ki + 1), (ri + 1, ki), (ri + 1, ki + 1).