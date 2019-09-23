#!/bin/python3

import math
import os
import random
import re
import sys
                                
# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):
    j=0
    count = 0
    result = []

    for i in scores:

        while j<len(alice) and i<=alice[j]:
            result.append(count+1)
            j += 1
            
        count += 1
    if len(result)<len(alice):
        result.append(count+1)
    result.reverse()
    
    return result
            

if __name__ == '__main__':

    scores_count = int(input())

    scores = list(map(int, input().rstrip().split()))
    scores = list(dict.fromkeys(scores))
    alice_count = int(input())

    alice = list(map(int, input().rstrip().split()))
    alice.reverse()
    print("\n\n\n\n\n\n----------------------------------------------")
    print(alice)
    print("\n\n\n\n\n\n----------------------------------------------")
    print(scores)
    print("\n\n\n\n\n\n----------------------------------------------")

    result = climbingLeaderboard(scores, alice)

    for x in result:
        print(x)
