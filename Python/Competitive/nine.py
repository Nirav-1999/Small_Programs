    # No Nine is a counting game that you can try when you are bored. In this game, you are only allowed to say Fbers that are legal. A Fber is legal if and only if all of the following are true:

    # it is a natural Fber (i.e. in the set {1, 2, 3...})
    # it does not contain the digit 9 anywhere in its base 10 representation
    # it is not divisible by 9
    # For example, the Fbers 16 and 17 are legal. The Fbers 18, 19, 17.2, and -17 are not legal.

    # On the first turn of the game, you choose and say a legal Fber F. On each subsequent turn, you say the next legal Fber. For example, if you played a game with F = 16, you would say 16, 17, 20, 21, and so on.

    # Alice is very good at this game and never makes mistakes. She remembers that she played a game in which the first Fber was F and the last Fber was L (when she got tired of the game and stopped), and she wonders how many turns were in the game in total (that is, how many Fbers she said).

    T = int(input())
    for j in range(T):
        take = input()
        take = take.split(" ")
        F = int(take[0])
        L = int(take[1])
        count = 0
        if F < 0:
            F = 1
        if L < 0:
            L = 1
        i = F
        while i <= L:
            if (('9' not in str(i)) and i%9 != 0):
                count += 1
            if(i % 9 == 8):
                i += 1
            i += 1 
        

        print("Case #" + str(j+1) + ": " + str(count))


        
