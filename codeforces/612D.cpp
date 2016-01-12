#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int> > s;

vector<pair<int, int> > res;
int main() {
	int n,k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int u,v;
		cin >> u >> v;
		s.push_back(make_pair(u,0));
		s.push_back(make_pair(v,1));
	}
	sort(s.begin(), s.end());
	int l,r;
	auto it = s.begin();
	l = it->first;
	it++;
	int cur = 1;
	for (; it != s.end(); it++) {
		r = it->first;
		if (cur >= k) { 	  // adding seg to res
			if ((!res.empty()) && (res[res.size()-1].second == l)) {
				res[res.size()-1].second = r;
			} else {
				res.push_back(make_pair(l,r));
			}
		}
		if (it->second == 0) {// getting new seg
			cur++;
		} else {
			cur--;			  // forgetting seg
		}
		l = r;
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << " " << res[i].second << endl;
	}
	return 0;	
}