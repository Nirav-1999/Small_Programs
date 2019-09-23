# As the football coach at your local school, you have been tasked with picking a team of exactly P students to represent your school. 
# There are N students for you to pick from. The i-th student has a skill rating Si, which is a positive integer indicating how skilled they are.

# You have decided that a team is fair if it has exactly P students on it and they all have the same skill rating. 
# That way, everyone plays as a team. Initially, it might not be possible to pick a fair team, so you will give some of the students one-on-one coaching. 
# It takes one hour of coaching to increase the skill rating of any student by 1.

# The competition season is starting very soon (in fact, the first match has already started!), 
# so you'd like to find the minimum number of hours of coaching you need to give before you are able to pick a fair team.

def take_input():
    N_P = input()
    N_P = N_P.split(" ")
    N_P = [int(x) for x in N_P]    
    return N_P
ans = []
T = int(input())
for k in range(T):
    N_P = take_input()
    no_s = N_P[0]
    no_p = N_P[1]
    skill = take_input()
    skill.sort()
    hrs = []
    count = 0

    for i in range(no_p-1):
        count+=skill[no_p-1]-skill[i]
    hrs.append(count)
    flag = no_p-1
    for i in range(no_p,len(skill)):
        count = count - (skill[i-1] - skill[i-no_p])
        count += (no_p-1)*(skill[i]-skill[i-1])
        hrs.append(count)

    ans.append('Case #'+ str(k+1) + ': ' + str(min(hrs)))

for answer in ans:
    print(answer)
