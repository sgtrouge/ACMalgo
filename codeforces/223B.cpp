#include <iostream>
using namespace std;

bool check[200001];

bool dp(string s, string t) {
	int dp[26];
        int dp_tmp[26];		
	for (int i = 0; i < 26; i++)	{
		dp[i] = -1;
		dp_tmp[i] = -1;
	}

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if ((dp[j] + 1 < t.size()) && (t[dp[j] + 1] == s[i])) {
				dp_tmp[s[i] - 97] = dp[j] + 1;	
				check[dp[j] + 1] = true;
			}			 	
		}

		for (int j = 0; j < 26; j++) {
			dp[j] = dp_tmp[j];
		}
	}
	
	for (int i = 0; i < t.size(); i++) {
		if (check[i] == false) return false;	
	}
	return true;
}

int main() {
	string s, t;
	cin >> s >> t;	
	if (dp(s, t)) cout << "Yes" << endl;
	else	      cout << "No"  << endl;
	return 0;
}

