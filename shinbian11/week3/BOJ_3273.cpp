#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } // 최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } // 최소공배수


int n, x, p1, p2, cnt;

int main() {

	F_I;
	
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	cin >> x;

	sort(v.begin(), v.end()); // 정렬

	p1 = 0;
	p2 = v.size()-1;

	while (p1 < p2) {
		if (v[p1] + v[p2] == x) {
			cnt += 1;
			p1 += 1;
		}
		else if (v[p1] + v[p2] <= x)  {
			p1 += 1;
		}
		else if (v[p1] + v[p2] >= x) {
			p2 -= 1;
		}
	}

	cout << cnt << '\n';

	return 0;
}