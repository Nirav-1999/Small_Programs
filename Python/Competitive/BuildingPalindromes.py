# Anna has a row of N blocks, each with exactly one letter from A to Z written on it. The blocks are numbered 1, 2, ..., N from left to right.

# Today, she is learning about palindromes. A palindrome is a string that is the same written forwards and backwards. For example, ANNA, RACECAR, AAA and X are all palindromes, while AB, FROG and YOYO are not.

# Bob wants to test how well Anna understands palindromes, and will ask her Q questions. The i-th question is: can Anna use all of the blocks numbered from Li to Ri, inclusive, rearranging them if necessary, to form a palindrome? After each question, Anna puts the blocks back in their original positions.

# Please help Anna by finding out how many of Bob's questions she can answer "yes" to.

T = int(input())
for i in range(T):
    line = input()
    line = line.split(" ")
    N = int(line[0])
    Q = int(line[1])
    string = input()
    quest = []
    count = 0
    for _ in range(Q):
        a = input()
        a = a.split(" ")
        a[0] = int(a[0])-1
        a[1] = int(a[1])
        quest.append(a)

    for ele in quest:
        flag = 0
        S = ele[0]
        E = ele[1]
        test = string[S:E]
        distinct = "".join(set(test))
        for letter in distinct:
            if test.count(letter)%2 != 0:
                flag += 1
        if flag <= 1:
            count += 1

    print("Case #" + str(i+1) + ": " + str(count))