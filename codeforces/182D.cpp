#include <iostream>
#include "math.h"
using namespace std;
string a,b;
int res = 0;
int za[100001];
int zb[100001];

void zfunc(int d[], string s) {
	int l = 0; 		int r = 0;	
	for (int i = 1; i < s.size(); i++) {
		int k;
		if (r < i) k = 1;
		else k = min(r-i+1, d[i-l]) + 1;
		while ((i+k-1 < s.size()) && (s[i+k-1] == s[k-1])) k++;
		k--;		d[i] = k;
		if (i+k-1 > r) {
			r = i+k-1;
			l = i;
		} 
	}
}
bool solve(int divi) {
	for (int i = divi; i < a.size(); i += divi) if (za[i] < divi) return false;
	for (int i = divi; i < b.size(); i += divi) if (zb[i] < divi) return false;
	return true;
}
int main() {
	cin >> a;
	cin >> b;
	zfunc(za,a);		zfunc(zb,b);
	int mi = min(a.size(), b.size());
	for (int i = 0; i < mi; i++) {
		if (a[i] != b[i]) break;
		if ((a.size() % (i+1) == 0) && (b.size() % (i+1) == 0)) {
			bool tmp = solve(i+1);
			if (tmp) {
				res++;
			}
		}
	}
	cout << res << endl;
	return 0;
}