#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // F_I 사용 시 주의) scanf 와 cin 혼합 사용 금지
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int main()
{
	// https://www.acmicpc.net/board/view/83220 참고

	F_I;

	ll n, m;
	ll mx = -1e18;
	cin >> n >> m;
	vector<ll> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}

	// ll s = 0; 으로 하면 안된다! 
	// 블루레이 개수 == n (블루레이 1개당 1개의 강의만 담는 경우 => 가장 많이 쪼개어서 담는 경우) 일 때도, 강의 시간들 중 최대의 용량을 가지는 블루레이를 이용해야 한다.
	// 예시) 강의 길이가 100 200 300 400 이고, 블루레이 4개에 나눠 담아야 한다면 => 블루레이 크기 중 최소 (즉, 정답)는 400이 되어야 한다 (강의들 중 최대 길이)
	ll s = mx;

	ll e = 1e18;

	while (s <= e) {

		ll mid = (s + e) / 2;
		ll cnt = 0;
		ll tmp = 0;

		for (int i = 0; i < n; i++) {
			if (tmp + v[i] > mid) {
				cnt += 1;
				tmp = 0;
			}
			tmp += v[i];
		}
		cnt += 1;

		if (cnt > m) {
			s = mid + 1;
		}
		else if (cnt < m) {
			e = mid - 1;
		}
		else { // cnt == m 
			e = mid - 1;
		}

		/*
		e = mid - 1의 역할은 조건을 만족하는 값의 범위를 점점 작게 만드는 것..
		cnt == M 인 블루레이 중 '최소' 값을 찾고 싶을 때 => cnt == M 일때, e = mid - 1; 을 하고, 답으로 s 를 취한다.

		역으로 cnt == M 인 블루레이 중 '최대' 값을 찾고 싶을 때 => s = mid + 1; 을 취하고 (조건을 만족하는 값의 범위를 점점 크게 만드는 것), 답으로 e 를 취한다.
		*/
	}

	cout << s << '\n';

	return 0;

}