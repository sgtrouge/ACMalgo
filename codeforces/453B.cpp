#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
vector <int> primearr = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int bitmask[61];
int dp[101][150000];
int last[101][150000];
int lastbm[101][150000];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < 60; i++) {
		for (int j = 0; j < primearr.size(); j++) {
			if (i % primearr[j] == 0) {
				bitmask[i] += 1 << j;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int tmp;
		for (int j = 0; j <= (1 << 17) -1; j++) {
			dp[i][j] = 1 << 20;
		}
		cin >> tmp;
		for (int j = 1; j < 60; j++) {
			int x = (1 << 17) - 1 - bitmask[j];
			for (int s = x; s > 0; s = (s-1) & x) {
				if (dp[i][s | bitmask[j]] > dp[i-1][s] + abs(tmp-j)) {
					dp[i][s | bitmask[j]] = dp[i-1][s] + abs(tmp-j);
					last[i][s | bitmask[j]] = j;
					lastbm[i][s | bitmask[j]] = s; 
				}
			}
		}
	}
	int res = 1 << 20;
	int reslast = 0;
	for (int i = 0; i <= (1 << 17) - 1; i++) {
		if (dp[n][i] < res) {
			res = dp[n][i];
			reslast = i;
		}
	}
	vector<int> resarr;	resarr.clear();
	for (int i = n; i >= 1; i--) {
		resarr.push_back(last[i][reslast]);
		reslast = lastbm[i][reslast];
	}
	for (int i = n-1; i >= 0; i--) cout << resarr[i] << " ";
	cout << endl;
}