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

int dp[1004][10];
int sum = 0;

int solve(int n) {
	
	// dp[i][j] : i번째 자리에 있는 수가 j일때, 오르막 수의 개수
	// dp[i][j] : dp[i-1][k] 들의 합 (단, 0 <= k <= j)

	// 예시) dp[2][4] : 2번째 자리에 있는 수가 4일때, 오르막 수의 개수는, 1번째 자리의 수가 0, 1, 2, 3, 4일때의 오르막 수들의 합이다.

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += (dp[i-1][k] % 10007); // 10007로 나누는 거 잊지 말 것!
			}
		}
	}

	for (int i = 0; i <= 9; i++) sum += dp[n][i];

	return sum % 10007;
}

int main()
{
	F_I;

	int n;
	cin >> n;

	cout << solve(n) << '\n';

	return 0;
}