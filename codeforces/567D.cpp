#include <iostream>
#include <algorithm>

using namespace std;
int b[200002];
int n, k, a, m;

bool check(int mid) {
	int tmp[200002];
	for (int i = 0; i < mid; i++) tmp[i] = b[i];
 	sort(tmp, tmp + mid);
 	tmp[mid] = n+1;
	int count = k;
	int start = 1;
	//cout << "mid is " << mid << endl;
	for (int i = 0; i < mid+1; i++) {
		while (start + a - 1 < tmp[i]) {
			start += (a+1);
			count--;
		}
		//cout << "count is " << count << endl;
		if (count <= 0) return true;
		start = tmp[i]+1;
	}
	return false;
}
int main() {
	cin >> n >> k >> a;
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	int l = 1; 	int r = n;	int res = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid) == false) {
			r = mid-1;
			res = mid;
		} else {
			l = mid+1;
		}
	}
	cout << res << endl;
	return 0;
}