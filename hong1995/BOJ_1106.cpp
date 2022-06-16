#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>>h;
int c, n, a, b, dp[100005], ans = 1e9;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		h.push_back({ a,b });
	}
	for (int i = 1; i <= 100001; i++) {
		for (int j = 0; j < h.size(); j++) {
			if ((i - h[j].first) < 0) continue;
			else {
				dp[i] = max(dp[i], dp[(i - h[j].first)] + h[j].second);
			}

		}
	}
	for (int i = 1; i <= 100000; i++) {
		if (dp[i] >= c) {
			cout << i << "\n";
			break;
		}
	}
}