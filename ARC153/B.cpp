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
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) {
		cin >> s[i];
	}
	int pa, pb, qa, qb;
	pa = qa = 1;
	pb = qb = 0;

	long long query;
	cin >> query;
	while (query--) {
		cin >> x >> y;
		x--; y--;
		pb = (pb + pa * x + h) % h;
		pa *= -1;
		qb = (qb + qa * y + w) % w;
		qa *= -1;
	}
	rep(i, h) {
		rep(j, w) {
			x = (pb + pa * i + h) % h;
			y = (qb + qa * j + w) % w;
			cout << s[x][y];
		}
		cout << endl;
	}
}
