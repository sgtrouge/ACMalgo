#include <iostream>
#include <sstream>
#include <assert.h>
int a[9][9];
using namespace std;
bool res;
bool check(int i, int j) {
	bool visit[10];
	for (int k = 0; k < 10; k++) visit[k] = false;
	for (int k = 0; k < 9; k++) {
		int ti = i + k/3;
		int tj = j + (k % 3);
		if (visit[a[ti][tj]]) return false;
		else visit[a[ti][tj]] = true;
	}
	return true;
}
int main() {
	string s;
	cin >> s;
	int c = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			a[i][j] = s[c] - '0';
			c++;
		}
	}
	res = true;
	for (int k = 0; k < 9; k++) {
		int hi = (k/3)*3;
		int hj = (k % 3)*3;
		res = res & check(hi,hj); 
		if (res == false) break;
	}
	if (res) cout << 1 << endl;
	else	 cout << 0 << endl;
}