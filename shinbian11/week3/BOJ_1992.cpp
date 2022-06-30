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

int n;
int arr[65][65];

void DivideAndConquer(int size, int x, int y) {
	int curr = arr[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (curr != arr[i][j]) {
				cout << "(";
				DivideAndConquer(size / 2, x, y);
				DivideAndConquer(size / 2, x, y + size / 2);
				DivideAndConquer(size / 2, x + size / 2, y);
				DivideAndConquer(size / 2, x + size / 2, y + size / 2);
				cout << ")";
				return;
			}
		}
	}

	cout << curr;

}

int main()
{
	
	F_I;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) arr[i][j] = str[j] - '0';
	}

	DivideAndConquer(n, 0, 0);

	return 0;

}