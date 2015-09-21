#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int a) {
	if (a == 1) return false;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) {
		 return false;
		}
	}
	return true;

}
int main(){
	int n;
	cin >> n;
	vector<int> res;
	for (int i = 2; i <= n; i++) {
		if (!isPrime(i)) continue;
		int pow = i;
		while (pow <= n) {
			res.push_back(pow);
			pow *= i;
		}		
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}