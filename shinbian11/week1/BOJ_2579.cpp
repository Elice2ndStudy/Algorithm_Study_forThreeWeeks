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

int stairs[304];
int dp[304];

int solve(int n) {

	if (n < 1) return 0;
	if (dp[n] != 0) return dp[n];
	

	// dp[n] : n번째 계단에서 가질 수 있는 최대의 합계 값 = n-2까지의 최대 합계 값 + n번째 값 / n-3까지의 최대 합계 값 + n-1 번째 값 + n번째 값
	// n-1번째까지의 최대 합계 값 + n번째 값 >> 이게 안 되는 이유는? 이것을 허용하면 n-2번째까지의 합 + n-1번째 깞 + n번째 값 이 답으로 되는 경우도 발생할 수 있으므로 (연속 3개의 계단은 밟을 수 없다)
	dp[n] = max(solve(n - 2) + stairs[n], solve(n - 3) + stairs[n - 1] + stairs[n]);
	
	return dp[n];
}

int main()
{
	F_I;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> stairs[i];
	
	cout << solve(n) << '\n';

	return 0;
}