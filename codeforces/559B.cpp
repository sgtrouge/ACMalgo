#include <iostream>
#include <string>
using namespace std;

bool check(string a, string b) {
	if (a == b) return true;
	if (a.size() % 2 == 1) return false;
	int l = a.size()/2;
	if ((check(a.substr(0,l), b.substr(0,l)) && check(a.substr(l,l), b.substr(l,l)))
	  || (check(a.substr(0,l), b.substr(l,l)) && check(a.substr(l,l), b.substr(0,l)))) {
		return true;
	}
	return false;
}

int main() {
	string a,b;
	cin >> a;
	cin >> b;
	if (check(a,b)) cout << "YES" << endl;
	else			cout << "NO" << endl;
}