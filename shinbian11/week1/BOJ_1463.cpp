#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int dp[1000004];

int solve(int n)
{
	if (n <= 1) return 0; // 탈출조건 : n이 1이면 최소 횟수는 0회니까 0 반환 (n을 1로 만들기 위한 연산이 필요없음)
	if (dp[n] != 0) return dp[n]; // memoization

	
	
	dp[n] = solve(n - 1) + 1;

	if (n % 3 == 0) { 
		dp[n] = dp[n] > solve(n / 3) + 1 ? solve(n / 3) + 1 : dp[n];
	}
	if (n % 2 == 0) { 
		dp[n] = dp[n] > solve(n / 2) + 1 ? solve(n / 2) + 1 : dp[n];
	}


	return dp[n];
}

int main()
{
	F_I;

	int n;
	cin >> n;
	cout << solve(n) << '\n';

	return 0;
}