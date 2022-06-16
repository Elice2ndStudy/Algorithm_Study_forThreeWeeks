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

int c, n;
int d[100004];

int main()
{
	F_I;

	cin >> c >> n;
	vector<pi> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	// d[i] : i원을 투자해서 모을 수 있는 최대 고객의 수

	// d[i]의 값을 찾는 법
	// max(d[i], 비교 1), max(d[i], 비교 2) => 두 번의 비교를 통해서 d[i]의 값 (최대 고객의 수) 을(를) 찾기

	// 비교 1. 어떠한 도시의 고객 확보에 들어가는 비용의 정수배만큼 홍보했을 때
	// 비교 2. 이전에 저장해놓은 최댓값에 한 번의 홍보를 더할 때


	// 도움 받은 글 : https://ongveloper.tistory.com/323


	for (int i = 1; i <= 100000; i++) {
		for (int j = 0; j < n; j++) {
			/*if (i % v[j].first == 0) {
				d[i] = max(d[i], (i / v[j].first) * v[j].second);
			}*/
			if (i - v[j].first >= 0) {
				d[i] = max(d[i], d[i - v[j].first] + v[j].second);
			}
		}
		if (c <= d[i]) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}