P1=0
P2=0
print("To plat the game press\nR for rock\nP for paper\nS for scissor")
for i in range(1000):
    c=input("Do you want to continue playing?\nEnter Y for yes and N for no\n")
    if c=="N":
        break
    a=input("1st Player Enter:")
    b=input("2nd Player Enter:")
    if a==b:
        print("Draw")
    elif a=="R" and b=="P":
        P2+=1
        print("Player 2 wins")
    elif a=="R" and b=="S":
        P1+=1
        print("Player 1 wins")
    elif a=="P" and b=="R":
        P1+=1
        print("Player 1 wins")
    elif a=="P" and b=="S":
        P2+=1
        print("Player 2 wins")
    elif a=="S" and b=="R":
        P2+=1
        print("Player 2 wins")
    elif a=="S" and b=="P":
        P1+=1
        print("Player 1 wins")
    else:
        print("Invalid Input")
print("The Scores Are:\n")
print("PLAYER 1=\t")
print(P1)
print("\nPlayer 2=\t")
print(P2)
if P1==P2:
    print("Its a DRAW!!!")
elif P1>P2:
    print("Player 1 WINS!!!")
else:
    print("Player 2 WINS!!!")
          
