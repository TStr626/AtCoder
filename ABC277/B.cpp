#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<string> vs(n);
	set<string> ss;
	set<char> suit = { 'H','D','C','S' };
	set<char> rank = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	jud = 1;
	rep(i, n) {
		cin >> vs[i];
		if (ss.count(vs[i])) {
			jud = 0;
		}
		if (!suit.count(vs[i][0])) {
			jud = 0;
		}
		if (!rank.count(vs[i][1])) {
			jud = 0;
		}
		ss.insert(vs[i]);
	}
	if (jud) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}