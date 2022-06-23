#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int names[1004];
int dp[1004][1004];
int n, m, ans = 1e6;

// dp[index][count] : index 번째 글자를 쓸 것이고, 현재 이미 그 줄에 count 칸만큼은 사용했을 때 >> 이때의 남게 되는 칸 수의 제곱의 합의 최솟값
// 그 줄에 계속 이어서 쓸 것인지 / 다음 줄에 쓸 것인지 결정!

int solution(int index, int count) {
	if (index >= n) return 0;

    // Before)은 안되고, After)는 되는 이유?!
    
	// Before) 
    // if (dp[index][count] != -1) return ans = dp[index][count];
    
	// After)
    int& ans = dp[index][count];
	if (ans != -1)
		return ans;

	// Case 1. 다음 줄에 쓸 경우 (다음 줄부터 발생하게 될 남은 칸 수의 제곱의 합들 + 이번 줄에서 발생한 남은 칸 수의 제곱) 
	ans = solution(index + 1, 1 + names[index]) + (m - count + 1) * (m - count + 1);

	// Case 2. 그 줄에 계속 이어서 쓸 수 있는 경우
	if (count + names[index] <= m) { 
		int ansTmp = solution(index + 1, count + names[index] + 1);
		ans = min(ans, ansTmp);
	}

	return ans;
}

int main()
{
	F_I;

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> names[i];

	// fill 함수 사용법에 대해 배움 (https://2jinishappy.tistory.com/68)
	fill(&dp[0][0], &dp[1003][1004], -1);

	cout<< solution(1, names[0] + 1);

	return 0;
}