#include <iostream>
#include <algorithm>
#include <utility> 
const int hi[4] = {-1, 0, 1, 0};
const int hj[4] = {0, 1, 0, -1};

int res_num[1001][1001];
int res_turn[1001][1001];
using namespace std;
int n,m;
int turn;
char a[1001][1001];
void dfs(int i, int j, int &count) {
	if ((a[i][j] != '.')) {
		return;
	}
	count++;
	a[i][j] = 'x';
	for (int k = 0; k < 4; k++) {
		int ti = i + hi[k];
		int tj = j + hj[k];
		if ((ti < 0) || (tj < 0)
			|| (ti >= n) || (tj >= m)) {
			continue;
		}
		dfs(ti, tj, count);
	}
}

void dfs2(int i, int j, int count) {
	if (a[i][j] == '*') {
		if (res_turn[i][j] != turn) {
			res_turn[i][j] = turn;
			res_num[i][j] += count;
		}
	}

	if (a[i][j] != 'x'){
		return;	
	}
	a[i][j] = '!';
	for (int k = 0; k < 4; k++) {
		int ti = i + hi[k];
		int tj = j + hj[k];
		if ((ti < 0) || (tj < 0)
			|| (ti >= n) || (tj >= m)) {
			continue;
		}
		dfs2(ti, tj, count);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			turn++;
			int count = 0;
			dfs(i,j, count);
			dfs2(i,j,count);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '*') {
				cout << res_num[i][j]+1;
			} else {
				cout << '.';
			}
		}
		cout << endl;
	}
	return 0;
}