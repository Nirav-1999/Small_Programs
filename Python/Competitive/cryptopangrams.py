# Problem
# On the Code Jam team, we enjoy sending each other pangrams, which are phrases that use each letter of the English alphabet at least once. 
# One common example of a pangram is "the quick brown fox jumps over the lazy dog". 
# Sometimes our pangrams contain confidential information — for example, CJ QUIZ: KNOW BEVY OF DP FLUX ALGORITHMS — so we need to keep them secure.

# We looked through a cryptography textbook for a few minutes, and we learned that it is very hard to factor products of two large prime numbers, 
# so we devised an encryption scheme based on that fact. First, we made some preparations:

# We chose 26 different prime numbers, none of which is larger than some integer N.
# We sorted those primes in increasing order. Then, we assigned the smallest prime to the letter A, the second smallest prime to the letter B, and so on.
# Everyone on the team memorized this list.
# Now, whenever we want to send a pangram as a message, we first remove all spacing to form a plaintext message. 
# Then we write down the product of the prime for the first letter of the plaintext and the prime for the second letter of the plaintext. 
# Then we write down the product of the primes for the second and third plaintext letters, and so on, ending with the product of the primes for the next-to-last and last plaintext letters. 
# This new list of values is our ciphertext. The number of values is one smaller than the number of characters in the plaintext message.

# For example, suppose that N = 103 and we chose to use the first 26 odd prime numbers, because we worry that it is too easy to factor even numbers. 
# Then A = 3, B = 5, C = 7, D = 11, and so on, up to Z = 103. Also suppose that we want to encrypt the CJ QUIZ... pangram above, so our plaintext is CJQUIZKNOWBEVYOFDPFLUXALGORITHMS. 
# Then the first value in our ciphertext is 7 (the prime for C) times 31 (the prime for J) = 217; the next value is 1891, and so on, ending with 3053.

# We will give you a ciphertext message and the value of N that we used. We will not tell you which primes we used, or how to decrypt the ciphertext. 
# Do you think you can recover the plaintext anyway?

import re, sys


def isPrime(n):
    return re.match(r'^1?$|^(11+?)\1+$', '1' * n) == None
answer=[]
c=1
T = int(input(""))
for j in range(T):
    num = 0
    dup =[]
    a= input()
    ans=''
    line1 = a.split(" ")
    all_num = []
    n = int(line1[0])
    l = int(line1[1])
    enc = input()
    enc = enc.split(" ")

    for i in range(1,n+1):
        if isPrime(i):
            if int(enc[0])%i == 0:
                num = i
                break
    all_num.append(num)
    for code in enc:
        all_num.append(int(int(code)/num))
        num = (int(int(code)/num))
    dup = []
    dup+=all_num
    dup.sort()
    dup = list(dict.fromkeys(dup))
    for number in all_num:
        ans+=chr(dup.index(number)+65)
    answer.append(ans)
for ans in answer:
    print("Case #"+str(c)+": "+ans)
    c+=1