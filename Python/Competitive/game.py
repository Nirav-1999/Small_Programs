''' Read input from STDIN. Print your output to STDOUT '''
    #Use input() to read input from STDIN and use print to write your output to STDOUT
# A new fighting game has become popular. 
# There are N number of villains with each having some strength. 
# There are N players in the game with each having some energy. 
# The energy is used to kill the villains. 
# The villain can be killed only if the energy of the player is greater than the strength of the villain. 
# Maxi is playing the game and at a particular time wants to know if it is possible for him to win the game or not with the given set of energies and strengths of players and villains. Maxi wins the game if his players can kill all the villains with the allotted energy.


def main():
    T = int(input())
    for _ in range(T):
        no_players = int(input())
        villain = input()
        hero = input()
        villain = villain.split(" ")
        hero = hero.split(" ")
        if '' in villain:
            villain.remove('')
        if '' in hero:
            hero.remove('')
        villain = list(map(int,villain))
        hero = list(map(int,hero))
        villain.sort()
        hero.sort()


        for j in range(no_players):
            if int(villain[j])>int(hero[j]):
                print("LOSE")
                break
        if j == no_players-1:
            print("WIN")
main()
