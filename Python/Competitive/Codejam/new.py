# Python3 program to check if an array is  
# subarray of another array  
  
# Function to check if an array is 
# subarray of another array 
def isSubArray(A, B, n, m): 
    # print(A)
    # print(B)
    # Two pointers to traverse the arrays 
    i = 0 
    j = 0
    count = 0
    # Traverse both arrays simultaneously 
    while (i < n and j < m): 
        # print("i =",i)
        # print("j =",j)
        # If element matches 
        # increment both pointers 
        if (A[i] == B[j]): 
  
            i += 1 
            j += 1
  
            # If array B is completely 
            # traversed 
            if (j == m): 
                count += 1
                j = 0 
          
        # If not, 
        # increment i and reset j 
        else: 
            i = i - j + 1 
            j = 0 
          
    return count 
  
# Driver Code 
T = int(input())
for case in range(T):
    N, K = list(map(int,input().split(" ")))
    A = list(map(int,input().split(" ")))
    sub_arr = [i for i in range(K,0,-1)]

    count = isSubArray(A, sub_arr, N, K)


    print("Case #{}: {} ".format(case+1,count))
