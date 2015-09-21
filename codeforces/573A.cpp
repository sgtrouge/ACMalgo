#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;
unordered_map<int, int> m;
int main() {
	int n;
	cin >> n; 
	bool res = true;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (res == false) break;
		for (int j = 2; j <= sqrt(tmp); j++) {
			int c = 0;
			while (tmp % j == 0) {
				c++;
				tmp = tmp/j;
			}
			if (c > 0) {
				if (i == 0) {
					m[j] = c;
				}
				else {
					if (j > 3 && m[j] != c) {
						res = false;
					}
				}
			}
		}
		if (tmp > 1) {
			if (i == 0) {
				m[tmp] = 1;
			}
			else {
				if (tmp > 3 && m[tmp] != 1) {
					res = false;
				}
			}
		}
	}
	if (res) cout << "Yes" << endl;
	else	 cout << "No" << endl;
	
	return 0;
}