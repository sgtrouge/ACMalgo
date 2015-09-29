#include <iostream>
#include <algorithm>
using namespace std;
int last[2000002];
int n;
int a[200001];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];	
	sort(a, a+n);
	int m = *max_element(a, a+n);
	int res = 0;
	for (int i = 0; i < n; i++) last[a[i]] = a[i];
	for (int j = 1; j <= 2*m; j++) last[j] = max(last[j], last[j-1]);

	for (int i = 0; i < n; i++) {
		if ((i > 0) && (a[i] == a[i-1])) continue;
		for (int j = 2;; j++) {
			int best = last[a[i]*j-1];
			res = max(res, best % a[i]);
			if (a[i]*j > m) break;
		}
	}
	cout << res << endl;
	return 0;
}