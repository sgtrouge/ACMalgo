#include <iostream>
#include "math.h"
#include <algorithm>
using namespace std;
int main() {
	string s,p;
	cin >> s >> p;
	int dp[10001];
	for (int i = 0; i < s.size(); i++) {
		dp[i] = 1;
		if (i == 0) continue;
		dp[i] += dp[i-1];
		if (i+1 < p.size()) continue;
		bool check = true;
		for (int j = 0; j < p.size(); j++) {
			if (s[i-p.size()+1+j] != p[j]) {
				check = false;
				break;
			}
		}
		if (check) {
			if (i+1 == p.size()) {
				dp[i] = 1;
				continue;
			}
			dp[i] = min(dp[i-p.size()]+1, dp[i]);
		}
	}
	cout << dp[s.size()-1] << endl;
	return 0;
}