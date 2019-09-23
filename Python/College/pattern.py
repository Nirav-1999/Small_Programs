"""
        1
       32
      654
    10987
"""

i = 1
max = 4

for j in range(max):
    i = int((j + 1)*(j+2)*0.5)
    for k in range(max - j - 1):
        print(" ",end='')
    for l in range(j+1):
        print(i,end='')
        i -= 1
    print("\n",end='')
