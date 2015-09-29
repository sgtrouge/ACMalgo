#include <iostream>
#include "math.h"
using namespace std;
long sum;
int main() {
	int n;
	cin >> n;
	long tmp;
	long res = -10000000000;
	long last = 0;
	sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		res = max(res, sum-last);
		last = min(last,sum); 
	}
	cout << res << endl;
	return 0;
}