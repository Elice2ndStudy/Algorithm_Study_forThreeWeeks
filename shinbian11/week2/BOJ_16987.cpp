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
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int s[10], w[10]; // s : 내구도, w : 무게
int egg; // egg : 계란 개수
int ans;

void EggBreak(int index) {

	if (index == egg) {
		int cnt = 0;
		for (int i = 0; i < egg; i++) {
			if (s[i] <= 0) {
				cnt++;
			}
		}
		if (ans < cnt) ans = cnt;
		return; 
	}

	if (s[index] <= 0) { // 손에 들고 있는 계란이 이미 깨져있으면 치지 않고 다음 계란으로 그냥 넘어간다.
		EggBreak(index + 1);
		return; // *** 필수! (다음 계란으로 넘어가야 하므로, return 이 없으면 현재 계란의 index는 유지된 채로 밑 코드로 넘어갈수도 있다.)
	}

	bool isAllEggsBreak = true;

	for (int i = 0; i < egg; i++) {
		if (index == i) continue; // 이미 선택한 계란에 대한 중복 선택 금지 처리

		if (s[i] > 0) {
			isAllEggsBreak = false; // 깨져있지 않은 계란이 하나라도 있다.

			s[i] -= w[index]; // i번째 계란의 내구성을 깎기
			s[index] -= w[i]; // 손에 들고있는 계란의 내구성을 깎기

			EggBreak(index + 1);


			s[i] += w[index]; // i번째 계란의 내구성 복구
			s[index] += w[i]; // 손에 들고있는 계란의 내구성 복구
		}
	}

	if (isAllEggsBreak) { // 깨지지 않은 다른 계란이 없으면 치지 않고 다음 계란으로 그냥 넘어간다.
		EggBreak(index + 1);
		// return; // 여기서 return은 필수 아님! (37줄과 다르게, 현재 계란의 index는 유지된 채로 밑 코드로 넘어간다 해도 어짜피 함수의 끝이다.)
	}

}

int main() {

	F_I;

	cin >> egg;
	for (int i = 0; i < egg; i++) {
		cin >> s[i] >> w[i];
	}


	EggBreak(0);

	cout << ans << '\n';
	
	return 0;
}