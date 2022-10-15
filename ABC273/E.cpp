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

struct node {
	long long val;
	long long prenode;
};
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	long long query;
	string s;
	
	cin >> query;
	vector<node> vn(1);
	vn[0] = { -1, 0 };
	map<long long, long long> mp;
	cur = 0;
	node nd;
	rep(i, query) {
		cin >> s;
		if (s == "ADD") {
			cin >> x;
			res = vn.size();
			nd = { x,cur };
			vn.push_back(nd);
			cur = res;
		}
		else if (s == "DELETE") {
			cur = vn[cur].prenode;
		}
		else if (s == "SAVE") {
			cin >> x;
			res = vn.size();
			nd = { -1,cur };
			vn.push_back(nd);
			mp[x] = res;
		}
		else if (s == "LOAD") {
			cin >> x;
			cur = mp[x];
			cur = vn[cur].prenode;
		}

		if (i) cout << ' ';
		cout << vn[cur].val;
	}
	cout << endl;

}