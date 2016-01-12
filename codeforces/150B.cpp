#include <iostream>
using namespace std;
int p[1001];
const int MODU = 1000000007;
int n, m, k;

void unite(int p1, int p2) {
	int total = p[p1] + p[p2];
	if (p[p1] < p[p2]) {
		p[p2] = p1;
		p[p1] = total;
	} else {
		p[p1] = p2;
		p[p2] = total;
	}
}

int root(int node) {
	while (p[node] > 0) {
		node = p[node];
	}
	return node;
}
int main() {
	cin >> n >> m >> k;
	int num = n;
	for (int i = 1; i <= n; i++) p[i] = -1;
	for (int i = 1; i <= n; i++) {
		int l,r;
		if (k % 2 == 1) {
			l = i;
			r = i;
			if (r + k/2 > n) continue;
			if (l - k/2 <= 0) continue;
		} else {
			l = i;
			r = i+1;
			if (r + k/2 -1 >  n) continue;
			if (l - k/2 +1 <= 0) continue;
		}
		cout << l << " " << r << endl;
		cout << "INSIDE" << endl;
		for (int j = 1; j <= k/2; j++) {
			int p1 = root(l);
			int p2 = root(r);
			cout << l << " with root " << p1 << endl;
			cout << r << " with root " << p2 << endl;
			if (p1 != p2)  {
				unite(p1,p2);
				num--;
			}
			l--;
			r++;
		} 
	}
	long long res = 1;
	for (int i = 1; i <= num; i++) {
		res = (res * m) % MODU;
	}
	cout << num << endl;
	cout << res << endl;
	return 0;
}