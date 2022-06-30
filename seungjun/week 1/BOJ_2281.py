# 데스노트
# https://www.acmicpc.net/problem/2281

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
names = []
for _ in range(n):
    names.append(int(input()))

print(names)