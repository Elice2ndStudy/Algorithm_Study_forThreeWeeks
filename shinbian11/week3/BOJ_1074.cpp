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

int n, r, c;
int arr[2 ^ 15 + 1][2 ^ 15 + 1];
int cnt;

void DivideAndConquer(int size, int x, int y) {

	//cout << "cnt x y : " << cnt << ' ' << x << ' ' << y << '\n';
	if (x == r && y == c) {
		cout << cnt << '\n';
		exit(0); // return; 하면 틀림! 출력하고 바로 프로그램 종료해야 됨
	}
	if (r >= x && r < x + size && c >= y && c < y + size) {
		DivideAndConquer(size / 2, x, y);
		DivideAndConquer(size / 2, x, y + size / 2);
		DivideAndConquer(size / 2, x + size / 2, y);
		DivideAndConquer(size / 2, x + size / 2, y + size / 2);
		//exit(0);
		//return;
	}
	else {
		cnt += size * size;
	}

	return;
}

int main()
{

	F_I;

	cin >> n >> r >> c;


	DivideAndConquer((1 << n), 0, 0);
	cout << cnt << '\n';

	return 0;

}