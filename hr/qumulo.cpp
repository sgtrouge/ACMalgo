#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <assert.h>

using namespace std;
struct trie
{
	int type; // 0 is null, 1 is char, 2 is nl
	char at;  // if type = 1 then at is assigned a single character
	bool nextnode[2]; // see if the nextnode '0' or '1' is possible
	int nextpos[2];  // position of nextnode in the vector
};

vector <trie> trienode;

void insert(string s, string t)
{
	int pos = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int c = s[i] - '0';
		if (trienode[pos].nextnode[c] == false) // If can't expand the trie, insert new node
		{
			trie nextcur;
			nextcur.nextnode[0] = false;		nextcur.nextpos[0] = 0;
			nextcur.nextnode[1] = false;		nextcur.nextpos[1] = 0;
			nextcur.type = 0;
			if (i == s.length() -1)
			{
				if (t == "[newline]") nextcur.type = 2; // If the current position on the tree represents
				else									// character, type = 1, if '\n' then type = 2
				{										// if null then type = 0 (by default)
					nextcur.type = 1;
					nextcur.at = t[0];
				}
			}
			trienode.push_back(nextcur);
			trienode[pos].nextpos[c] = trienode.size()-1;
			trienode[pos].nextnode[c] = true;
		}
		pos = trienode[pos].nextpos[c];
	}
}

void solve(string s)
{
	int pos = 0;
	for (int i = 0; i < s.length(); i++) 	// Repeatly move on the trie, once hit a node 
	{										// that represents a character, print that out
		int c = s[i] - '0';					// and return to root, otherwise proceed.
		pos = trienode[pos].nextpos[c];
		if (trienode[pos].type != 0)
		{
			if (trienode[pos].type == 2) cout << endl;
			else	 	                 cout << trienode[pos].at;
			pos = 0;
		}
	}	
}
int main()
{
	trie root;
	root.nextnode[0] = false;	root.nextnode[1] = false;
	trienode.push_back(root);
	int n;
	cin >> n;		string s1, s2;
	string ss;   	getline(cin, ss);
	for (int i = 0; i < n; i++)
	{
		getline(cin, ss);
		stringstream kk;		kk << ss;
		if (ss[0] == ' ')
		{				
			s1 = " ";	kk >> s2;				 //Watch for empty character
		}
		else			kk >> s1 >> s2;			
		insert(s2, s1);
	}
	string t;		string text;
	while (getline(cin, t))		text = text + t; //Since the text can be in many lines, 
												 //concatenation might be useful
	solve(text);
	return 0;
}
