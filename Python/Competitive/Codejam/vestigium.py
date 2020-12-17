def check_dup(mat):
    count = 0
    for ele in mat:
        if len(set(ele)) < len(ele):
            count += 1
    return count

def calc_trace(mat,n):
    trace = 0
    for i in range(n):
        trace += mat[i][i]
    return trace

T = int(input())
for i in range(T):
    N = int(input())
    mat = []
    for _ in range(N):
        mat.append(list(map(int,input().split(" "))))
    # print(mat)
    tr_mat =  [list(j) for j in zip(*mat)]
    # print(tr_mat)
    a = check_dup(mat)
    b = check_dup(tr_mat)
    c = calc_trace(mat,N)

    print("Case #{}: {} {} {}".format(i+1,c,a,b))