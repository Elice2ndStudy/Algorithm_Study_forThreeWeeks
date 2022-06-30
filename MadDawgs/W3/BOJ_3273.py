import sys
from turtle import right
input = sys.stdin.readline

def myFunc():
    myInput.sort()
    count = 0
    left = 0
    right = n - 1
    while left < right:
        sum = myInput[left] + myInput[right]
        if sum == x:
            count += 1
            left += 1
            right -= 1
        elif sum < x:
            left += 1
        else:
            right -= 1
    return count

n = int(input())
myInput = list(map(int, input().split()))
x = int(input())

print(myFunc())