# Someone just won the Code Jam lottery, and we owe them N jamcoins! However, when we tried to print out an oversized check, we encountered a problem. The value of N, which is an integer, includes at least one digit that is a 4... and the 4 key on the keyboard of our oversized check printer is broken.

# Fortunately, we have a workaround: we will send our winner two checks for positive integer amounts A and B, such that neither A nor B contains any digit that is a 4, and A + B = N. Please help us find any pair of values A and B that satisfy these conditions.


t = int(input())
case = 0
numbers=[]
for i in range(t):
    numbers.append(input())
for num in numbers:
    case += 1
    a=0
    b=int(num)

    while '4' in num:
        a = int(num) - 3*10**(len(num)-num.index('4')-1)
        num = str(a)

    b = b - a
    print("Case #" + str(case) + ": " + str(a) + " " + str(b))
