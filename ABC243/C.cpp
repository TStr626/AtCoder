#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

struct pos {
	long long x;
	long long y;
	long long num;
};
bool operator<(pos a, pos b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	else if (a.y != b.y) {
		return a.y < b.y;
	}
	else {
		return a.num < b.num;
	}
}

int main() {
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod;
	cin >> n;
	vector<pos> p(n);
	rep(i, n) {
		cin >> p[i].x >> p[i].y;
		p[i].num = i;
	}
	sort(p.begin(), p.end());
	string s;
	cin >> s;

	map<int, int> mp;
	rep(i, n) {
		j = p[i].num;
		if (s[j] == 'R') {
			mp[p[i].y] = 1;
		}
		else if (mp[p[i].y] > 0) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}