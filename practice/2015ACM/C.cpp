#include <iostream>
#include "math.h"

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else	    return gcd(b, a % b);
}
int main() {
	long long dpt[60];
	long long dpb[60];
	long long red,white;
	cin >> red >> white;
	dpt[0] = 1; 	dpb[0] = 1;
	long long common = gcd(red,white);
	dpt[1] = red/common;   dpb[1] = (red+white)/common;
	for (int i = 2; i <= white; i++) {
		long long gt = white*(white-1);
		long long gb = (red+white)*(red+white-1);
		common = gcd(gt,gb);
		gt /= common;
		gb /= common;

		dpt[i] = gt*dpt[i-2];
		dpb[i] = gb*dpb[i-2];
		common = gcd(dpt[i], dpb[i]);
		dpt[i] /= common;
		dpb[i] /= common;

		dpt[i] = dpt[i]*(red+white) + red*dpb[i];
		dpb[i] = dpb[i]*(red+white);
		common = gcd(dpt[i], dpb[i]);
		dpt[i] /= common;
		dpb[i] /= common;
	}
	cout << dpt[white] << "/" << dpb[white] << endl;
	return 0;
}