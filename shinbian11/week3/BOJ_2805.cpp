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

ll n, m;
ll s = 0, e = 1e18;

int main() {

	F_I;

	cin >> n >> m;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	ll mid = (s + e) / 2;
	ll sum = 0;
	ll answer = 0;

	while (s <= e) {

		mid = (s + e) / 2;
		sum = 0;

		for (int i = 0; i < n; i++) {
			if (v[i] <= mid) continue;
			sum += v[i] - mid;
		}

		if (sum >= m) {

            // sum 이 최소 m 이상인 경우에서만 mid의 최대를 구하면 된다. 
            // 이 코드가 sum >= m 을 조건으로 하는 if문 안에 있어야 한다!
			answer = max(answer, mid); 

			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	cout << answer << '\n';

	return 0;
}