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


int n, k;
int p1, p2;
int len;
int answer = 1e6;
vector<int> v;

int main() {

	F_I;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 1) v.push_back(i);
	}

	p1 = 0;
	p2 = k - 1;
	len = v.size();

	if (p2 > len - 1) answer = -1;
	else {
		while (true) {
			if (p1 >= len || p2 >= len) break;
			answer = min(answer, v[p2] - v[p1] + 1);
			p1++;
			p2++;
		}
	}

	cout << answer << '\n';

	return 0;
}