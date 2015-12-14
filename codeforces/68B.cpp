#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <iomanip>

using namespace std;
int main() {
	set<pair<double, int> > numset;
	int n;
	double k;
	cin >> n >> k;
    std::cout << std::setprecision(6) << std::fixed;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numset.insert(make_pair(temp, i));
		if (n == 1) {
			cout << temp << endl; 
			return 0;
		}
	}

	double l, r;
	l = 0; 
	r = 1000;
	double res = 0;
	while (r - l > 0.00000000001) {
		double mid = (l +r)/ 2;
		set<pair<double, int> > tmpset = numset;
			//	for (set<pair<double,int> >::iterator it = tmpset.begin(); it != tmpset.end(); it++) 
	//			cout << it->first << " ";
	//		cout << endl;
		bool find = false;
		while (true) {
			pair<double, int> minof = *tmpset.begin();
			pair<double, int> maxof = *tmpset.rbegin();
			if (minof.first >= mid || maxof.first <= mid) {
				if (minof.first >= mid) {
					res = mid;
					l = mid;
				} else {
					r = mid;
				}
				break;
			}

			double dist = mid - minof.first;
			double req  = dist * 100/(100-k);
			double edit = min(req, maxof.first - mid);
			//cout << minof.first << "," << maxof.first << endl;
			//cout << dist << "," << req << "," << edit << endl;
			tmpset.erase(make_pair(maxof.first, maxof.second));
			tmpset.insert(make_pair(maxof.first - edit, maxof.second));
			tmpset.erase(make_pair(minof.first, minof.second));
			tmpset.insert(make_pair(minof.first + edit - edit*k/100, minof.second));
		}
	}
	cout << res << endl;
	return 0;
}