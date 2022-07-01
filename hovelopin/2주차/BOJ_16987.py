# [BOJ] 16987 / 계란으로 계란치기 / 실버1 / 파이썬
# 정답보고 해결했지만 ( 정확하게 이해는 못함 )
import sys
input = sys.stdin.readline

n = int(input())
egg_list = [list(map(int,input().split())) for _ in range(n)]

def solve(cur):
    # 현재 마지막까지 다 확인한 상태라면 깨진거를 계산해준다.
    if cur == len(egg_list):
        cnt = 0
        for s,w in egg_list:
            if s <= 0:
                cnt += 1
        return cnt
    # 현재 손에 든 계란 내구도가 0이라면 깨짐 => 즉 , 다음꺼를 탐색한다.
    if egg_list[cur][0] <= 0:
        return solve(cur+1)

    # 안깨진 계란이 남아있으면 넘어가고 없으면 다음꺼를 본다.
    for i in range(len(egg_list)):
        if i == cur:
            continue
        if egg_list[i][0] > 0:
            break
    else:
        return solve(cur+1)

    # 시물레이션 ( 때려보기 )
    answer = 0
    for i in range(len(egg_list)):
        if i == cur:
            continue
        if egg_list[i][0] <= 0:
            continue

        # 내구도를 계산해주는 과정
        egg_list[i][0] -= egg_list[cur][1]
        egg_list[cur][0] -= egg_list[i][1]

        answer = max(answer , solve(cur+1))

        # 다음 차례로 가기 위해서 기존에 뺴주었던거 다시 더해준다.
        egg_list[i][0] += egg_list[cur][1]
        egg_list[cur][0] += egg_list[i][1]
    return answer

print(solve(0))




