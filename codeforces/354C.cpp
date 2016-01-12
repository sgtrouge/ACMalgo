#include <iostream>
#include <algorithm>
using namespace std;
int lefta[1000001];
int righta[1000001];
int a[300001];
int n, k;
int main() {
	cin >> n >> k;
	int start = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		start = max(start, a[i]);
	}
	sort(a, a+n);
	a[n] = 2000001;
	int lpointer = 0;
	int rpointer = -1;
	for (int i = 1; i <= 1000000; i++) {
		righta[i] = -1;
		lefta[i] = -1;
		while (a[lpointer] < i) lpointer++;
		if (max(a[lpointer] - k, 1) <= i)
			lefta[i] = lpointer;

		while (max(a[rpointer + 1] - k, 1) <= i) rpointer++;
		if  ((rpointer >= 0) && (a[rpointer] >= i))
			righta[i] = rpointer;
	}

	for (int i = start; i >= 1; i--) {
		int j = 1;
		int cr = -1;
		while (i * j <= start) {
			if (lefta[i*j] - cr <= 1) {
				cr = max(cr, righta[i*j]);
				if (cr == n-1) {
					cout << i << endl;
					return 0;
				}
			}
			else {
				break;
			}
			j++;
		}
	}
}