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
	string s;
	cin >> s;
	vector<set<int>> vs;

	i = 0;
	vs.push_back({});
	vector<bool> on(26, false);
	for (auto c : s) {
		if (c == '(') {
			vs.push_back({});
			i++;
		}
		else if (c == ')') {
			for (auto d : vs[i]) {
				on[d] = false;
			}
			vs.pop_back();
			i--;
		}
		else if (on[c - 'a'] == false) {
			vs[i].insert(c - 'a');
			on[c - 'a'] = true;
		}
		else {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

}