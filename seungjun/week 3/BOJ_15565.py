# 귀여운 라이언
# https://www.acmicpc.net/problem/15565

n, k = map(int, input().split())
dolls = list(map(int, input().split()))
ans = 1e9

# 라이언의 위치들을 저장해주자
ryan = []
for i in range(n):
    if dolls[i] == 1:
        ryan.append(i)

start = 0
end = k-1

# 라이언의 갯수가 k보다 낮으면 -1를 출력해주고 종료
if len(ryan) < k:
    print(-1)
    exit(0)
while True:
    doll = ryan[end] - ryan[start] + 1
    ans = min(ans, doll)

    if end == len(ryan) - 1:
        break

    # 슬라이더를 오른쪽으로 한 칸씩 옮겨준다
    start += 1
    end += 1
print(ans)


