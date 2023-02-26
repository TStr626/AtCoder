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
	set<pos> ms;
	pos p = { 0,0 };
	ms.insert(p);
	
	string s;
	cin >> n >> s;
	rep(i, n) {
		switch (s[i]) {
		case 'R': p.x++; break;
		case 'L': p.x--; break;
		case 'U': p.y++; break;
		case 'D': p.y--; break;
		}
		if (ms.count(p)) {
			yes();
			return 0;
		}
		ms.insert(p);
	}
	no();
}