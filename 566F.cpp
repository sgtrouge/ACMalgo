#include <iostream>
#include "math.h"
using namespace std;

int dp[1000001];
int a[1000001];
int main() {
	int res = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}
	for (int i = 1000000; i >= 2; i--) {
		if (a[i] == 0) continue;
		dp[i] = a[i];
		int j = 2;
		while (i * j <= 1000000) {
			dp[i] = max(dp[i], a[i] + dp[i*j]);
			j++;
		}
		res = max(res, dp[i]);
	}	
	if (a[1] == 1) res++;
	cout << res << endl;
}