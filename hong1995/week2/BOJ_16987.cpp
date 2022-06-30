#include <iostream>
using namespace std;
int n, s[10], w[10], ans;
void dfs(int idx, int cnt) {
	if (cnt == n) {
		cout << n;
		exit(0);
	}
	if (idx == n) {
		ans = max(ans, cnt);
		return;
	}
	if (s[idx] <= 0 || cnt == n - 1) {
		dfs(idx + 1, cnt);
		return;
	}

	int next = cnt;
	for (int i = 0; i < n; ++i) {
		if (i == idx || s[i] <= 0) continue;
		s[idx] -= w[i];
		s[i] -= w[idx];
		if (s[i] <= 0) next++;
		if (s[idx] <= 0) next++;
		dfs(idx + 1, next);
		next = cnt;
		s[idx] += w[i];
		s[i] += w[idx];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i] >> w[i];
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}