#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int n;
	int res = 0;
	set<pair<int, int>> pairset;
	pairset.clear();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;
		pairset.insert(make_pair(b,a));
	}
	int minend = 0;
	for (auto it = pairset.begin(); it != pairset.end(); it++){
		if (minend < it->second) {
			res++;
			minend = it->first;
		} 
	}
	cout << res << endl;;
}