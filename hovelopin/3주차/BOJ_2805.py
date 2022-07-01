# [BOJ] 2805 / 나무 자르기 / 실버2 / 파이썬
n , m = map(int,input().split())
tree = list(map(int,input().split()))

# 1부터 tree의 최대 길이까지를 시작과 끝으로 잡는다
start = 1
end = max(tree)

while start <= end:
    mid = (start+end) // 2
    length = 0

    # tree를 전체적으로 돌면서 tree의 길이가 mid보다 크면 짤라서 length에 더한다.
    for l in tree:
        if l >= mid :
            length += l-mid
            if length > m:
                break

    # 만약 length가 m보다 크다면 mid를 낮게 잡은것이기 때문에 start 부분을 올려주고 아니라면 end를 낮춰준다.
    if length >= m:
        start = mid + 1
    else:
        end = mid - 1
print(end)