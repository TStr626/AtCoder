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
void yes() {
	cout << "Yes" << endl;
}
void no() {
	cout << "No" << endl;
}
void vec_h(vector<long long> a) {
	int n = a.size(), i;
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}
void vec_v(vector<long long> a) {
	for (auto c : a) {
		cout << c << endl;
	}
}

struct pos {
	long long x;
	long long y;
};
bool operator<(pos a, pos b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y < b.y;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m >> h >> k;
	string s;
	cin >> s;
	set<pos> st;
	rep(j, m) {
		cin >> x >> y;
		st.insert({x, y});
	}
	map<char, long long> mp;
	mp['R'] = 0; mp['L'] = 1; mp['U'] = 2; mp['D'] = 3;
	vector<long long> dx = { 1,-1,0,0 }, dy = { 0,0,1,-1 };
	x = 0; y = 0;
	rep(i, n) {
		cur = mp[s[i]];
		x += dx[cur]; y += dy[cur];
		h--;
		if (h < 0) {
			no();
			return 0;
		}
		if (h < k && st.count({ x,y })) {
			st.erase({ x,y });
			h = k;
		}
	}
	yes();
	
}