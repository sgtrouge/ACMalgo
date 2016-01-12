#include <iostream>
#include <map>

using namespace std;
int a[4001];
int last[1000001];
int count[100001];
int dp[4001][4001];
int main() {
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		count[a[i]]++;
		res = max(res, count[a[i]] - 1);
		for (int j = i-1; j >= 1; j--) {
			int lasti = last[a[i]];
			if (lasti >= j) {
				dp[j][i] = dp[j][lasti];
				continue;
			}
			dp[j][i] = max(dp[j][i], dp[lasti][j] + 1);
			res = max(res, dp[j][i]);
		}
		last[a[i]] = i;
	}
	cout << res+1 << endl;
	return 0;
}